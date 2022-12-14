// Fixed a silly bug, caused by having the wrong sign for convex hull.
// For some reason, it's really hard (using my test generator) to find a wrong test case.
// Perhaps because of block size value.
// UPD: (see comment below) this time it isn't very hard to find a wrong test case when block size
// is 1 and bound for b is small.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

int const BLOCKSIZE=
#ifdef LOCAL
1
#else
500 // TODO is this ok?
#endif
;


std::vector<std::vector<int>> ad;
std::vector<int> a,b;
std::vector<int> sa,sb /* sum of a/b of par */,first,last; // pre order traversal index
// NOTE: sa / sb: pre order traversal index (not node index) -> current (can be lazy) value

int num;
void dd(int x){
	first[x]=num;
	auto const sax=sa[num];
	auto const sbx=sb[num]; // must be computed
	++num;
	for(int y:ad[x]){
		sa[num]=sax+a[y];
		sb[num]=sbx+b[y];
		dd(y);
	}
	last[x]=num;
}

struct block_t{
	struct pt{
		int64_t ab;
		int b;
		int ind; // absolute
	};
	std::vector<pt> pts; // sorted by non decreasing b

	struct pt1{
		int64_t ab;
		int b;
		int64_t operator()(int lazy_d)const{
			return ab+b*(int64_t)lazy_d;
		}
	};
	std::vector<pt1> hullpos,hullneg; // decreasing max b, increasing max ab
	// (ab = -ab if neg)

	int blockleft,size;
	std::vector<int> pts_ind; // [i] = ind of i+blockleft in pts
	int lazy_d;

	block_t(int blockleft,int size):pts(size),
		blockleft(blockleft),size(size),pts_ind(size),lazy_d()
	{
		for(int i=0;i<size;++i){
			pts[i]={sa[i+blockleft]*(int64_t)sb[i+blockleft], sb[i+blockleft], i+blockleft};
		}
		std::sort(begin(pts),end(pts),[](pt x,pt y){return x.b<y.b;});
		for(int i=0;i<size;++i)
			pts_ind[pts[i].ind-blockleft]=i;
		refresh<true>();
		refresh<false>();
	}

	template<bool neg>
	void refresh(){ // complexity: BLOCKSIZE
		// only call when a part (not all) of the block is modified. if the whole block is modified
		// call add_lazy instead.
		assert(lazy_d==0);

		auto& hull=neg ? hullneg : hullpos;

		auto const procab=[](int64_t ab)->int64_t{return neg?-ab:ab;};
		hull.clear();

		auto const proc=[&](pt p){
			auto& [ab,b,ind]=p;
			ab=sa[ind]*(int64_t)b;
			assert(sb[ind]==b);

			if(b==0)return;

			while(not hull.empty() and procab(hull.back().ab)<=procab(ab))
				hull.pop_back();
			while(hull.size()>=2){ // check ccw
				auto M=hull.back();
				auto N=hull.end()[-2];
				pt1 P{ab,b};

				N.ab-=M.ab;N.b-=M.b;
				P.ab-=M.ab;P.b-=M.b;
				if(P.b*(long double)(N.ab)-(long double)(P.ab)*N.b >=0)
					hull.pop_back();
				else
					break;
			}
			hull.push_back({ab,b});
		};

		if(neg)
			std::for_each(pts.rbegin(),pts.rend(),proc);
		else
			std::for_each(pts.begin(),pts.end(),proc);

		std::reverse(begin(hull),end(hull));
	}

	void add_lazy(int d){ // total complexity = total hull.size() + number of calls
		assert(d>0);
		lazy_d+=d;
		while(hullpos.size()>1 and hullpos.back()(lazy_d)<=hullpos.end()[-2](lazy_d))
			hullpos.pop_back();
		while(hullneg.size()>1 and hullneg.back()(lazy_d)>=hullneg.end()[-2](lazy_d))
			hullneg.pop_back();
	}

	int64_t get_abs()const{
		int64_t out=0;
		if(not hullpos.empty()) out=std::max(out,std::abs(hullpos.back()(lazy_d)));
		if(not hullneg.empty()) out=std::max(out,std::abs(hullneg.back()(lazy_d)));
		// these vectors can be empty when all b values are zero
		assert([&]{
					int64_t out1=0;
					for(int i=0;i<size;++i)
						out1=std::max(out1,
								std::abs((sa[blockleft+i]+lazy_d)*int64_t(sb[blockleft+i]))
								);
					assert(out==out1);
					return out==out1;
				}());
		return out;
	}

};
std::vector<block_t> blocks;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nquery;std::cin>>n>>nquery;
	ad.resize(n);
	for(int i=1;i<n;++i){
		int pi;std::cin>>pi;--pi;
		assert(pi<i);
		ad[pi].push_back(i);
	}

	a.resize(n);for(int& ai:a)std::cin>>ai;
	b.resize(n);for(int& bi:b)std::cin>>bi;
	num=0;
	first.assign(n,-1);
	last.assign(n,-1);
	sa.resize(n);sb.resize(n);
	sa[0]=a[0];
	sb[0]=b[0];
	dd(0);

	assert(std::find(begin(first),end(first),-1)==end(first));
	assert(std::find(begin(last),end(last),-1)==end(last));
	std::transform(begin(sb),end(sb),begin(sb),[](auto x){return std::abs(x);}); // does not affect result
	a.clear(); // mark as unused
	b.clear();

	blocks.reserve((n+BLOCKSIZE-1)/BLOCKSIZE);
	for(int i=0;i<n;i+=BLOCKSIZE)
		blocks.emplace_back(i,std::min(n-i,BLOCKSIZE));

	while(nquery--){
		char type;std::cin>>type;
		if(type=='1'){ // update
			int v,xx;std::cin>>v>>xx;--v;
			int l=first[v],r=last[v];

#if 0 // CAL
			for(int i=0;i<n;++i){
				std::cout<< (sa[i]+blocks[i/BLOCKSIZE].lazy_d)<<' '<<(sb[i])<<',';
			}
			std::cout<<'\n';
			std::cout<<"upd "<<l<<' '<<r<<' '<<xx<<'\n';
#endif

			if(l%BLOCKSIZE!=0 or r/BLOCKSIZE*BLOCKSIZE<=l){
				int blockleft=l/BLOCKSIZE;
				{ // push lazy (only takes time, no-op)
					std::for_each(
							begin(sa)+blocks[blockleft].blockleft,
							begin(sa)+blocks[blockleft].blockleft+blocks[blockleft].size,

							[d=blocks[blockleft].lazy_d](int& x){x+=d;});
					blocks[blockleft].lazy_d=0;
				}

				auto r1=std::min(r,blocks[blockleft].blockleft+blocks[blockleft].size);
				std::for_each(begin(sa)+l, begin(sa)+r1, [xx](int& x){x+=xx;});
				blocks[blockleft].refresh<true>();
				blocks[blockleft].refresh<false>();

				l=r1;
			}
			if(r%BLOCKSIZE!=0 and l<r){
				int blockright=r/BLOCKSIZE;
				std::for_each(
						begin(sa)+blocks[blockright].blockleft,
						begin(sa)+blocks[blockright].blockleft+blocks[blockright].size,

						[d=blocks[blockright].lazy_d](int& x){x+=d;});
				blocks[blockright].lazy_d=0;

				std::for_each(
						begin(sa)+blocks[blockright].blockleft,
						begin(sa)+r,

						[xx](int& x){x+=xx;});
				blocks[blockright].refresh<true>();
				blocks[blockright].refresh<false>();

				r=blocks[blockright].blockleft;
				assert(l<=r);
			}

			for(int b=l/BLOCKSIZE,endb=r/BLOCKSIZE;b<endb;++b)
				blocks[b].add_lazy(xx);
		}else{ // get
			assert(type=='2');

#if 0 // CAL
			for(int i=0;i<n;++i){
				std::cout<< std::abs((sa[i]+blocks[i/BLOCKSIZE].lazy_d)*int64_t(sb[i]))<<' ';
			}
			std::cout<<'\n';
#endif

			int v;std::cin>>v;--v;
			int l=first[v],r=last[v];
			int64_t out=0;

			if(l%BLOCKSIZE!=0 or r/BLOCKSIZE*BLOCKSIZE<=l){
				int blockleft=l/BLOCKSIZE;
				auto const r1=std::min(r,blocks[blockleft].blockleft+blocks[blockleft].size);
				std::for_each(begin(sa)+l,begin(sa)+r1,
						[d=blocks[blockleft].lazy_d, &out](auto const& x){
							auto ind=&x-&sa[0];
							out=std::max(out,std::abs((x+d)*int64_t(sb[ind])));
						});

				l=r1;
			}
			if(r%BLOCKSIZE!=0 and l<r){
				int blockright=r/BLOCKSIZE;
				std::for_each(begin(sa)+blocks[blockright].blockleft,begin(sa)+r,
						[d=blocks[blockright].lazy_d, &out](auto const& x){
							auto ind=&x-&sa[0];
							out=std::max(out,std::abs((x+d)*int64_t(sb[ind])));
						});

				r=blocks[blockright].blockleft;
				assert(l<=r);
			}

			for(int b=l/BLOCKSIZE,endb=r/BLOCKSIZE;b<endb;++b)
				out=std::max(out,blocks[b].get_abs());

			std::cout<<out<<'\n';
		}
	}
}