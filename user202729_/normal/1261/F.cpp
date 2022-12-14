/*
Isn't this problem easy? I think that the only reason why I can't solve this problem int the virtual contest
is that I spent too much time on D and E, and don't even have the time to think about this problem.

Given that this is F and I solved it so easily, I should expect a WA...?

UPD: realize that I calculated the complexity wrong and the solution won't pass.
Still, I think this is less "observation-based" than E, and significantly easier than some F
int older contests.
Didn't calculate the complexity very carefully but this is about O(64) times faster than the previous solution.
(64 is a large number indeed.)

UPD2: constant factor optimization. Total size is at most 160MB which is << 256MB. Should fit the memory limit
(unless the overhead of dynamic memory allocation is too high)
*/

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

int const MOD=998244353;

using seg=std::pair<int64_t,int64_t>;

std::vector<seg> read_a_set(){
	int n;std::cin>>n;
	std::vector<seg> out(n);
	for(auto& [l,r]:out){
		std::cin>>l>>r;
		++r;
	}
	std::sort(begin(out),end(out));

	auto iter=begin(out);
	for(auto [l,r]:out){
		if(iter!=begin(out) and iter[-1].second>=l)
			iter[-1].second=std::max(iter[-1].second,r);
		else
			*iter++={l,r};
	}

	out.erase(iter,end(out));
	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	auto sa=read_a_set();
	auto sb=read_a_set();
	std::vector<int64_t> evinc,evdec;

	for(int z=2;z--;std::swap(sa,sb)){
		auto const process=[&](int64_t const l,int64_t const r){
			auto const size=r-l;
			assert((size^(size-1))>=size);
			assert((l&-size)==l);
			
			auto const push=[&](int64_t i){
				evinc.push_back(i);
				evdec.push_back(i+size);
			};

			for(auto const [l2,r2]:sb){
				auto i=l2&-size;

				push(l^i);

				i+=size;
				if(i>=r2)continue;
				push(l^i);

				auto j=(r2-1)&-size;
				if(j<=i)continue;
				push(l^j);

				j-=size;
				if(j<=i)continue;
				push(l^j);
			}
		};
		for(auto [l,r]:sa){
			for(int64_t bit=1;l<r;bit<<=1){
				if(l&bit){ process(l,l+bit); l+=bit; }
				if(r&bit){ process(r-bit,r); r-=bit; }
			}
			assert(l==r);
		}
	}
	assert(evinc.size()==evdec.size());

	if(evinc.size()>20480000) return 1;

	std::sort(begin(evinc),end(evinc));
	std::sort(begin(evdec),end(evdec));
	evinc.push_back(INT64_MAX);
	evdec.push_back(INT64_MAX);

	int curdeg=0;
	int64_t lastl=-1,ans=0;
	auto i1=evinc.begin();
	auto i2=evdec.begin();

	auto const process_event=[&](int64_t x,int deg){
		if(deg==1 and curdeg==0){
			lastl=x;
		}
		curdeg+=deg;
		assert(curdeg>=0);
		if(deg==-1 and curdeg==0){
			assert(lastl>=0);
			ans=(ans+ (x-lastl)%MOD* ((lastl+x-1)%MOD)%MOD * ((MOD+1)/2)) %MOD;
		}
	};

	while(true){
		if(*i1<*i2){
			process_event(*i1,1);
			++i1;
		}else if(*i2<INT64_MAX){
			process_event(*i2,-1);
			++i2;
		}else
			break;
	}
	std::cout<<ans<<'\n';
}