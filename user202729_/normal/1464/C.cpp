





#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	unsigned n; int64_t t; std::cin>>n>>t;
	std::string s; s.reserve(n); std::cin>>s;
	assert(s.size()==n);
	n=-1;

	t-=((int64_t)1<<(s.back()-'a')); s.pop_back();
	t+=((int64_t)1<<(s.back()-'a')); s.pop_back();
	// the rest of the characters can either be + or -
	
	std::array<int, 26> count{};
	for(auto ch: s) count[ch-'a']++;
	s.clear();

	if(0){
fail:
		std::cout<<"No\n";
		return 0;
	}

	int64_t least=t, most=t; // shifted
	for(int type=0; type<26; ++type){
		// after being shifted, all integers in [least, most] are reachable

		if(least==most){
			least-=count[type]; most+=count[type];
			assert((least&1)==(most&1));
			if(least&1) goto fail;
			// the shift right below will make the condition true in next step
		}else{
			least-=count[type]; most+=count[type];
		}

		// shift for next type
		while(least&1) ++least;
		least>>=1;

		//while(most&1) --most;
		most>>=1;

		if(least>most) goto fail;
	}

	if(not(least<=0 and 0<=most)) goto fail;

	std::cout<<"Yes\n";
}