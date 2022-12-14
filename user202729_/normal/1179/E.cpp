/*
 * [I didn't read the editorial or see any non-sample failed test cases]
 *
 * UPD: Miscalculate the complexity. The previous algorithm uses at least O(n^2) queries.
 * Idea: if n = l, for every choice of k segments, each of length 1, it's possible to choose the
 * rest. ==> algorithm: binary search for each segment.
 * 
 * Does not work int the general case. Nestings cannot always be expanded.
 * Idea: divide and conquer. Problem: easy-to-check condition is not always necessary.
 * (Condition: for some x, there's some a such that the number of y values larger than a is (......))
 * 
 * Divide and conquer does work.
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<numeric>
#include<cassert>
#include<iostream>
#include<vector>
#include<chrono>
#include<random>
std::mt19937 engine( std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count());

int nfunc;int64_t rangeval;
int64_t f(int fnindex,int64_t x){
	assert(0<=fnindex and fnindex<nfunc);
	assert(0<=x and x<=1000000000000000000LL);
	std::cout<<"? "<<1+fnindex<<' '<<x<<std::endl;
	int64_t out;std::cin>>out;
	assert(0<=out and out<=rangeval);
	return out;
}

int64_t invf(int fnindex,int64_t l,int64_t r,int64_t const target){
	assert(l<=r);
	for(auto step=1LL<<62;step;step>>=1)
		if(r-step>=l){
			auto val=f(fnindex,r-step);
			if(val>=target){
				r-=step;
				if(val==target) break;
			}
		}
	assert(f(fnindex,r)==target);
	return r;
}

std::vector<std::pair<int64_t,int64_t>> out;

void solve(std::vector<int> fns,int64_t minval,int64_t maxval,int64_t l,int64_t r){
	std::cerr<<" ** fns =";
	for(auto x:fns) std::cerr<<' '<<x;
	std::cerr<<"\n";

	auto const segval=rangeval/nfunc;
	assert(minval%segval==0 and maxval%segval==0 and minval<maxval and l<r);

	for(auto fnindex:fns){
		assert(f(fnindex,l)<=minval);
		assert(f(fnindex,r)>=maxval);
	}
	assert((maxval-minval)/segval==(int)fns.size());
	if(fns.size()==1){
		out[fns[0]]={l,r};
		return;
	}

	auto lsize=(int)fns.size()/2;
	auto rsize=(int)fns.size()-lsize;
	auto midval=minval+segval*lsize;

	// now partition fns by increasing invf at (l,r,midval), at [lsize]
	struct item{ int fnindex; int64_t val; };
	std::vector<item> fnv(fns.size());
	std::transform(begin(fns),end(fns),begin(fnv),[](int fnindex){ return item{fnindex,0}; });
	auto first=begin(fnv),last=end(fnv);
	auto l1=l,r1=r;

	int64_t x;
	while(true){
		std::swap(*first,first[std::uniform_int_distribution<int>(0,int(last-first-1))(engine)]);
		auto const pivotfi=first->fnindex;
		x=invf(pivotfi,l1,r1,first->val=midval);
		std::for_each(first+1,last,[&](item& i){ i.val=f(i.fnindex,x); });
		// now item.val = value evaluated at x

		auto iter1=std::partition(first,last,[&](item i){ return i.val>midval; });
		auto iter2=std::partition(iter1,last,[&](item i){ return i.val>=midval; });
		if(iter2-begin(fnv)>=lsize and end(fnv)-iter1>=rsize){ // ok
			first=begin(fnv)+lsize;
			assert(iter1<=first and first<=iter2);
			break;
		}else if(iter2-begin(fnv)<lsize){
			first=iter2;
		}else{
			last=iter1;
		}
	}

	assert(first-begin(fnv)==lsize);
	std::for_each(begin(fnv),first,[&](item i){ return f(i.fnindex,x)<=midval; });
	std::for_each(first,end(fnv),[&](item i){ return f(i.fnindex,x)>=midval; });

	fns.resize(lsize);
	std::transform(begin(fnv),first,begin(fns),[&](item i){ return i.fnindex; });
	solve(std::move(fns),minval,midval,l,x);

	fns.resize(rsize);
	std::transform(first,end(fnv),begin(fns),[&](item i){ return i.fnindex; });
	solve(std::move(fns),midval,maxval,x,r);

	return;

	/*
		for(auto x:remaining_fns) assert(f(x,lastr)<=lastval);
		assert(rangeval-lastval>=segval*remaining_fns.size());

		std::vector<int> upfns=std::move(remaining_fns);
		std::vector<int> downfns; downfns.reserve(upfns.size());
		lastval+=segval;

		int64_t r=1000000000000000000LL;
		assert(not upfns.empty());
		while(1){
			std::swap(upfns.back(),upfns[std::uniform_int_distribution<int>(0,(int)upfns.size()-1)(engine)]);
			int fnindex=upfns.back();
			upfns.pop_back();

			auto new_up_end=std::partition(begin(upfns),end(upfns),[&](auto fnindex){
					return f(fnindex,r)>lastval;
					});
			downfns.insert(end(downfns),new_up_end,end(upfns));
			upfns.erase(new_up_end,end(upfns)); // The size of upfns is expected to be reduced by half
			// therefore the expected total number of f queries int partition calls is 2*n

			if(upfns.empty()){
				out[fnindex]={lastr,r};
				lastr=r;
				// lastval=lastval;
				remaining_fns=std::move(downfns);
				break;
			}else{
				downfns.push_back(fnindex);
			}
		}
	}
	*/
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>nfunc>>rangeval;
	out.resize(nfunc);

	std::vector<int> fns(nfunc);
	std::iota(begin(fns),end(fns),0);
	solve(std::move(fns),0,rangeval,0,1000000000000000000LL);

	std::cout<<"!\n";
	for(auto [l,r]:out)std::cout<<l<<' '<<r<<'\n';
}