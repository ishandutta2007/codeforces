// time-limit: 1000
// problem-url: https://codeforces.com/contest/1599/problem/J
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// ... what happened?

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	std::vector<int> b(n);
	for(auto& it: b) {
		std::cin>>it;
	}
	

	// duplicates doesn't matter

	// consider graph, etc. there must be cycle length  2
	//
	// case 1: even length cycle  two nonempty set with equal sum
	//
	// case 2: odd length cycle  odd sized set with even sum
	//  even 1s and odd 0s
	//  one 0, (two 0|two 1)

	
	// any even number?
	auto even1=std::find_if(begin(b), end(b), [&](auto it){return it%2==0;});

	// given a, b and c that forms an odd length cycle, prints the answer
	auto const print3=[&](auto a, auto B, auto c){
		assert(a!=B); assert(B!=c); assert(c!=a);
		int s=*a+*B+*c;
		assert(s%2==0);
		auto const any=s/2-*c;
		std::cout<<"YES\n"
			<<s/2-*a<<' '
			<<s/2-*B<<' '
			<<any;
		for(auto it=b.begin(); it!=b.end(); it++) if(it!=a and it!=B and it!=c){
			std::cout<<' '<<*it-any;
		}
		std::cout<<'\n';
	};

	if(even1!=b.end()){
		auto even2=std::find_if(even1+1, end(b), [&](auto it){return it%2==0;});
		if(even2!=b.end()){
			auto even3=std::find_if(even2+1, end(b), [&](auto it){return it%2==0;});
			if(even3!=b.end()){
				// 3 even numbers, okay
				print3(even1, even2, even3);
				return 0;
			}
		}

		// not 3 even numbers
		auto odd1=std::find_if(begin(b), end(b), [&](auto it){return it%2!=0;});
		if(odd1!=b.end()){
			auto odd2=std::find_if(odd1+1, end(b), [&](auto it){return it%2!=0;});
			if(odd2!=b.end()){
				// 1 even number and 2 odd numbers
				print3(even1, odd1, odd2);
				return 0;
			}
		}
	}

	// if all false:
	//  no even
	//  even, but rest is {no two 0 and no two 1}
	//     (at most) even + one 0 + one 1
	//
	// only case 1 (two nonempty sets with equal sum) left now, find such set (by marking and calling printAnswer)
	//
	// mark: 1, -1, 0, must be some nonzero
	// case 1: set 1 nonempty, set 2 empty     }   cover all cases
	// case 2: set 2 nonempty, set 1 arbitrary }


	bool doCompress=false;
	if(even1==b.end()){
		// all odd numbers in range [1..=1e6]
		doCompress=true;
		// in this case compress the value to speed up algorithm (actually unnecessary complexity...)
		for(auto& x: b){
			assert(x%2!=0);
			x=(x+1)>>1;
		}
		// now: all numbers in [1..=5e5]
	}
	if(not doCompress) assert(n<=3);
	

	std::vector<int> mark(b.size());

	// given mark is nonzero and the corresponding sum is zero, print the answer
	auto const printAnswer=[&]{
		// check that the found set is correct
		assert([&]{
			int sum {};
			for(int i=0; i<(int)b.size(); ++i) sum+=b[i]*mark[i];
			assert(sum==0);
			return true;
		}());

		// compute the answer
		std::vector<int> positive, negative, rest;
		for(int i=0; i<(int)b.size(); ++i){
			int value=b[i];
			if(doCompress) value=value*2-1;
			switch(mark[i]){
				case 1: positive.push_back(value); break;
				case -1: negative.push_back(value); break;
				case 0: rest.push_back(value); break;
				default: assert(false); __builtin_unreachable();
			}
		}

		std::cout<<"YES\n";
		int value=0;
		assert(positive.size()==negative.size());
		assert(not positive.empty());
		for(int i=0; i<(int)positive.size(); ++i){
			std::cout<<value<<' ';
			value=positive[i]-value;
			std::cout<<value<<' ';
			value=negative[i]-value;
		}
		assert(value==0);

		for(auto x: rest) std::cout<<x<<' ';
		std::cout<<'\n';
	};

	int const HALF=14;

	int const S=HALF*500000; // alternatively could be 3 numbers and sum 3e6 (still fits)
	using B=std::bitset<S*2+1>;


	std::vector<B> data(HALF+1);

	// iterate over nonzero combinations of first group (extends to all in array)
	// because of symmetry only need to consider count>0, and for count=0 consider both for complete
	auto const work=[&](auto work, int i, int count, int sum)->bool{
		if(i==0) return false;
		--i;

		// consider this one ++ (every nonzero combination has some with ++)
		if([&](int count, int sum){
			if(count==0 and sum==0){
				// okay found?
				return true;
			}
			if(count<0){count=-count; sum=-sum;}
			data[count][sum+S]=true;
			if(count==0) data[count][-sum+S]=true;
			return false;
		}(count+1, sum+b[i])){
			// found solution in this group
			mark[i]=1;
			return true;
		}

		if(work(work, i, count, sum)){ return true; }
		if(work(work, i, count+1, sum+b[i])){ mark[i]=1; return true; }
		if(work(work, i, count-1, sum-b[i])){ mark[i]=-1; return true; }
		return false;
	};

	if(work(work, std::min(n, HALF), 0, 0)){
		// okay found in first group
		printAnswer();
		return 0;
	}

	if(n<=HALF){
		// no solution
		std::cout<<"NO\n"; return 0;
	}


	// include zero
	assert(not data[0][S]);
	data[0][S]=true;


	// iterate over last-positive combinations of second group to find something already in the set (may also be zero)
	auto const work2=[&](auto work2, int i, int count, int sum)->bool{
		if(i==HALF) return false;
		--i;

		if([&](int count, int sum){
			if(count<0){count=-count; sum=-sum;}
			if(data[count][sum+S]){
				// okay found
				return true;
			}
			return false;
		}(count+1, sum+b[i])){
			// okay found
			mark[i]=1;
			return true;
		}

		if(work2(work2, i, count, sum)){ return true; }
		if(work2(work2, i, count+1, sum+b[i])){ mark[i]=1; return true; }
		if(work2(work2, i, count-1, sum-b[i])){ mark[i]=-1; return true; }
		return false;
	};

	if(work2(work2, std::min(n, HALF*2), 0, 0)){
		// found such a set? Then brute force through set 1 again
		int curCount=0, curSum=0;
		for(int i=0; i<(int)mark.size(); ++i){
			curCount+=mark[i];
			curSum+=mark[i]*b[i];
		}

		// consider all combinations of set 1, including empty
		auto const work3=[&](auto work3, int i, int count, int sum)->bool{
			if(i==0) {
				if(count==0 and sum==0){
					return true;
				}
				return false;
			}
			--i;

			if(work3(work3, i, count, sum)){ return true; }
			if(work3(work3, i, count+1, sum+b[i])){ mark[i]=1; return true; }
			if(work3(work3, i, count-1, sum-b[i])){ mark[i]=-1; return true; }
			return false;
		};
		bool success=work3(work3, HALF, curCount, curSum);
		assert(success);

		printAnswer();
		return 0;

	}else{
		// can't find, considered all nonzero combinations of first std::min(n, HALF*2) elements
		assert(n<HALF*2);
		std::cout<<"NO\n"; return 0;
	}
}