#pragma GCC optimize ("O3")
#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<map>
#include<tuple>
#include<vector>
#include<bitset>
#include<set>
#include<iostream>

int constexpr maxm=2000;

/*
struct t{
	using word =uint64_t;
	static const int wt=64;

	static int ctz(word x){
		return __builtin_ctzll(x);
	}

	std::array<word,(maxm+wt-1)/wt> d;
	int cnt;

	int y1,y2; // certificate or -1

	t():d{},cnt(),y1(-1),y2(-1){}

	bool operator<(t const& x)const{
		return cnt<x.cnt;
	}

	void updcert(t const& pre){
		y1=y2=-1;
		for(int w=0;w<d.size();++w){
			auto x=d[i]&~pre.d[i];
			if(x)
				y1=w*wt+ctz(x);

			x=pre.d[i]&~d[i];
			if(x)
				y2=w*wt+ctz(x);
		}
		if(y1<0 or y2<0)
			y1=y2=-1;
	}
};
*/

std::map<int,std::tuple<int,int,int>> indices_with_cert; // nxt ind -> {pre ind, y1, y2}

std::vector<std::bitset<maxm>> full_shl; // why is this faster :(

struct t{
	uint32_t cnt_shl_16_or_ind;
	std::bitset<maxm> d;

	int ind;
	mutable int y1,y2; // certificate or -1
	// mutable because this does not affect ordering in set

	t(int ind):cnt_shl_16_or_ind(ind),d{},ind(ind),y1(-1),y2(-1){}

	t(const t&)=delete;
	t(t&&)=default;

	bool operator<(t const& x)const{
		return cnt_shl_16_or_ind<x.cnt_shl_16_or_ind;
		//return std::tie(cnt,ind)<std::tie(x.cnt,x.ind);
	}

	void rmcert()const{
		indices_with_cert.erase(ind);
		y1=y2=-1;
	}

	void updcert(t const& pre)const{
		assert(pre.ind!=ind);
		y1=(d&~pre.d)._Find_first();
		if(y1<d.size()){
			y2=(pre.d&~d)._Find_first();
			if(y2<d.size()){
				indices_with_cert[ind]={pre.ind,y1,y2};
				return;
			}
		}

		rmcert();
	}

	void ff(int l,int r){
		d^=full_shl[l];
		d^=full_shl[r];
		// cnt=d.count();
		cnt_shl_16_or_ind=(uint32_t)d.count()<<16|ind;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol,nq;std::cin>>nrow>>ncol>>nq;

	std::set<t> s;

	std::vector<decltype(s)::iterator> rows;rows.reserve(nrow);
	for(int i=0;i<nrow;++i){
		auto [iter,success]=s.emplace(i);
		rows.push_back(iter);
	} // now all cert == -1 is correct

	// NOTE all updcert/rmcert calls will edit indices_with_cert
	indices_with_cert.clear();

	{
		full_shl.clear();
		full_shl.emplace_back();
		full_shl.back()=~full_shl.back();
		while(full_shl.size()<ncol+1)
			full_shl.push_back(full_shl.back()<<1);
	}

	for(int z=nq;z--;){
		int a,l,r;std::cin>>a>>l>>r;
		--a;--l;
		auto iter=rows[a];
		assert(iter!=end(s));

		auto nxt=std::next(iter);
		auto node=s.extract(iter);
		if(nxt!=end(s)){
			if(nxt==begin(s))
				nxt->rmcert();
			else{
				auto pre=std::prev(nxt);
				nxt->updcert(*pre);
			}
		}

		t& ti=node.value();
		ti.ff(l,r);
		auto [iter1,inserted,node1]=s.insert(std::move(node));
		assert(inserted);

		if(iter1!=begin(s)){
			auto pre=std::prev(iter1);
			iter1->updcert(*pre);
		}else
			iter1->rmcert();

		nxt=std::next(iter1);
		if(nxt!=end(s)){
			nxt->updcert(*iter1);
		}

		if(indices_with_cert.empty()){
			std::cout<<"-1\n";
		}else{
			auto [nxti,mapped]=*indices_with_cert.begin();
			auto [prei,y1a,y2a]=mapped;
			auto [x1,x2]=std::minmax(prei,nxti);
			auto [y1,y2]=std::minmax(y1a,y2a);

			assert(x1<x2);
			assert(y1<y2);
			assert([&]{
				if(!((rows[x1]->d[y1]!=rows[x1]->d[y2])
					and(rows[x2]->d[y1]!=rows[x2]->d[y2])
					and(rows[x1]->d[y1]!=rows[x2]->d[y1])
					)){
					std::cerr<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<'\n';
					return false;
				}
				return true;
			}());

			std::cout<<x1+1<<' '<<y1+1<<' '<<x2+1<<' '<<y2+1<<'\n';
		}
	}
}