// {deleted comments}
// Why so many WA's... [I didn't view any failed test cases]
// The algorithm is obviously correct.
//
// Correction: the O(n**2) merge algorithm is incorrect. Changed to a n**2*something one.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int const MAX_NSTATE=70; // 8 choose 4. (surprisingly small in comparison with 2**8)

std::vector<int> states;

using dist_t=std::array<std::array<int64_t,MAX_NSTATE>,MAX_NSTATE>; // [start mask][stop mask] = min cost
// mask: [0] = leftmost
std::vector<dist_t> mem; // [log2 offset]

dist_t merge(dist_t const& a,dist_t const& b){
	dist_t out;
	for(auto x=states.size();x--;)
	for(auto z=states.size();z--;){
		out[x][z]=INT64_MAX/2;
		for(auto y=states.size();y--;)
			out[x][z]=std::min(out[x][z],a[x][y]+b[y][z]);
	}
	return out;
}

dist_t const& getmem(int x){
	assert(x==(x&-x));
	int index=__builtin_ctz(x);
	while(index>=(int)mem.size())
		mem.push_back(merge(mem.back(),mem.back()));
	return mem[index];
}

dist_t solve(int x){
	assert(x>0);
	auto out=getmem(x&-x);
	x-=x&-x;
	while(x){
		out=merge(out,getmem(x&-x));
		x-=x&-x;
	}
	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npol,maxjmp,nstone,nspecial;
	std::cin>>npol>>maxjmp>>nstone>>nspecial;

	std::vector<int> indexof(1<<maxjmp,-1);

	for(int mask=0;mask<(1<<maxjmp);++mask){
		if(__builtin_popcount(mask)==npol){
			indexof[mask]=(int)states.size();
			states.push_back(mask);
		}
	}
	assert((int)states.size()<=MAX_NSTATE);

	std::vector<int> cost(maxjmp);
	for(int& x:cost) std::cin>>x;


	struct specialstone{
		int pos,val;
	};
	std::vector<specialstone> specialstones(nspecial);
	for(auto& [pos,val]:specialstones){ std::cin>>pos>>val;--pos; }
	std::sort(begin(specialstones),end(specialstones),[&](auto a,auto b){ return a.pos>b.pos; });

	auto const specialvalue=[&](int pos){
		auto iter=std::lower_bound(begin(specialstones),end(specialstones),pos,
				[&](auto a,int b){ return a.pos>b; });
		return (iter==end(specialstones) or iter->pos!=pos) ? 0 : iter->val;
	};

	{
		std::vector distempty(2<<maxjmp,std::vector<int64_t>(2<<maxjmp));
		for(auto x=(unsigned)distempty.size();x--;){
			for(auto z=(unsigned)distempty.size();z--;)
				distempty[x][z]=INT64_MAX/2;
			if(__builtin_popcount(x)==npol){
				distempty[x][x]=0;
				auto first=x&-x;
				auto rest=x-first;
				for(int len=1;len<=maxjmp;++len)
					if(not ((first<<len)&rest)){
						auto newmask=rest|(first<<len);
						if(newmask<distempty.size())
							distempty[x][newmask]=cost[len-1];
					}
			}
		}

		for(auto y=(unsigned)distempty.size();y--;)if(__builtin_popcount(y)==npol)
		for(auto x=(unsigned)distempty.size();x--;)if(__builtin_popcount(x)==npol)
		for(auto z=(unsigned)distempty.size();z--;)
			distempty[x][z]=std::min(distempty[x][z],distempty[x][y]+distempty[y][z]);

		mem.emplace_back();
		auto& m1=mem[0];
		for(auto x=states.size();x--;)
		for(auto z=states.size();z--;)
			m1[x][z]=distempty[states[x]][states[z]<<1];
	}

	dist_t cur;
	{
		std::vector dist1(1<<maxjmp,std::vector<int64_t>(1<<maxjmp));
		for(auto x=(unsigned)dist1.size();x--;){
			for(auto z=(unsigned)dist1.size();z--;)
				dist1[x][z]=INT64_MAX/2;
			if(__builtin_popcount(x)==npol){
				dist1[x][x]=0;
				auto first=x&-x;
				auto rest=x-first;
				for(int len=1;len<=maxjmp;++len)
					if(not ((first<<len)&rest)){
						auto newmask=rest|(first<<len);
						if(newmask<dist1.size())
							dist1[x][newmask]=cost[len-1]+specialvalue(__builtin_ctz(first)+len);
					}
			}
		}

		for(auto y=(unsigned)dist1.size();y--;)if(__builtin_popcount(y)==npol)
		for(auto x=(unsigned)dist1.size();x--;)if(__builtin_popcount(x)==npol)
		for(auto z=(unsigned)dist1.size();z--;)
			dist1[x][z]=std::min(dist1[x][z],dist1[x][y]+dist1[y][z]);

		for(auto x=states.size();x--;)
		for(auto z=states.size();z--;){
			cur[x][z]=dist1[states[x]][states[z]];
		}
	}

	int sh=0;
	// cur = dist from pos 0 -> sh

	while(sh<nstone-maxjmp){
#if !SLOW
		while(not specialstones.empty() and specialstones.back().pos<=sh)
			specialstones.pop_back();
		if(specialstones.empty() or specialstones.back().pos>sh+maxjmp){
			int nxtsh=nstone-maxjmp;
			if(not specialstones.empty())
				nxtsh=std::min(nxtsh,specialstones.back().pos-maxjmp);
			assert(sh<nxtsh);

			//assert(std::cerr<<"mul "<<nxtsh-sh<<'\n');
			cur=merge(cur,solve(nxtsh-sh));
			sh=nxtsh;
		}else{
#endif
			dist_t nxt;
			for(auto x=states.size();x--;){
				for(auto z=states.size();z--;)
					nxt[x][z]=INT64_MAX/2;
				for(auto z=states.size();z--;)
					if(not (states[z]&1))
						nxt[x][indexof[states[z]>>1]]=cur[x][z]; // do nothing

				for(auto z=states.size();z--;){
					auto mask=states[z];
					auto first=mask&-mask;
					auto rest=mask-first;
					for(int len=1;__builtin_ctz(first)+len<=maxjmp;++len)
						if(not ((first<<len)&rest)){
							assert(not ((rest|(first<<len))&1));
							auto newmask=(rest|(first<<len))>>1;
							nxt[x][indexof[newmask]]=std::min(nxt[x][indexof[newmask]],
									cur[x][z]+cost[len-1]+specialvalue(__builtin_ctz(first)+len+sh));
						}
				}
			}
			//assert(std::cerr<<"nxt\n");
			++sh;
			cur=nxt;

			for(auto x=states.size();x--;){
				for(unsigned z=0;z<states.size();++z){
					// shrink cur[x][z] -> cur[x][other value]
					auto mask=states[z];
					auto first=mask&-mask;
					auto rest=mask-first;
					for(int len=1;__builtin_ctz(first)+len<maxjmp;++len)
						if(not ((first<<len)&rest)){
							auto newmask=rest|(first<<len);
							cur[x][indexof[newmask]]=std::min(cur[x][indexof[newmask]],
									cur[x][z]+cost[len-1]+specialvalue(__builtin_ctz(first)+len+sh));
						}
				}
			}

#if !SLOW
		}
#endif
	}
	assert(sh==nstone-maxjmp);

	std::cout<<cur[indexof[(1<<npol)-1]][indexof[((1<<npol)-1)<<(maxjmp-npol)]]<<'\n';
}