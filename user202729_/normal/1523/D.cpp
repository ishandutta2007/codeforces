// time-limit: 3000
// problem-url: https://codeforces.com/contest/1523/problem/D

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// this one is trivially hackable if the random seed is not random enough (?)
// alternatively make random seed equal to SHA256 hash of input, harder to hack (still possible in theory, just try 2^30-ish times)
// { ==== Begin library RandomEngine.h ====
std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

// } ==== End library RandomEngine.h ====
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numFriend; std::cin>>numFriend;
	int numBit; std::cin>>numBit;
	int _; std::cin>>_;
	
	std::vector<int64_t> data(numFriend);
	for(auto& it: data) {
		it=0;
		for(int bit=0; bit<numBit; ++bit){
			char c; std::cin>>c;
			it|=int64_t(c-'0')<<bit;
		}
	}

	struct{int pop, mask /* compressed by pivot in reverse bit order */ ; int64_t pivot;} result{};
	for(int _=0; _<30; ++_){
		auto pivot=data[std::uniform_int_distribution{0, numFriend-1}(engine)];
		std::vector<int> count(1<<__builtin_popcountll(pivot));

		for(auto value: data){
			int compressedValue {}; // NOTE in reversed bit order
			for(auto tmp=pivot; tmp; tmp-=tmp&-tmp){
				compressedValue=compressedValue<<1|bool(value&tmp&-tmp);
			}
			count[compressedValue]++;
		}

		for(int bit=(int)count.size(); bit>>=1;)
			for(int mask=0; mask<(int)count.size(); ++mask)
				if(mask&bit)
					count[mask-bit]+=count[mask];

		for(int mask=0; mask<(int)count.size(); ++mask)
			if(count[mask]>=((numFriend+1)>>1) and __builtin_popcount(mask)>result.pop)
				result={__builtin_popcount(mask), mask, pivot};
	}

	int i=__builtin_popcountll(result.pivot);
	int64_t finalResult {};
	for(auto tmp=result.pivot; tmp; tmp-=tmp&-tmp){
		i--;
		if(result.mask>>i&1) finalResult+=  tmp&-tmp ;
	}

	for(int bit=0; bit<numBit; ++bit)
		std::cout<<char('0'+(finalResult>>bit&1));
	std::cout<<'\n';
	
}