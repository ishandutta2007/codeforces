#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

[[nodiscard]] int64_t constexpr inv(int64_t val, int64_t MOD)  {
	int64_t a=val,b=MOD, ax=1,bx=0;
	while(b){
		int64_t q=a/b, t=a%b;
		a=b; b=t;
		t=ax-bx*q; ax=bx; bx=t;
	}
	assert(a==1);
	if(ax<0)ax+=MOD;
	return ax;
}

int64_t multiply(int64_t val, int64_t b, int64_t MOD){
	uint64_t result=
		(uint64_t)val*(uint64_t)b-
		uint64_t((long double)val*b/MOD)*(uint64_t)MOD;
	result+=MOD;
	if(result>=MOD){
		result-=MOD;
		if(result>=MOD) result-=MOD;
	}
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t t; int number; std::cin>>t>>number;

	std::vector<int64_t> pos(number);
	{
		int64_t last{};
		for(auto& it: pos){
			int value; std::cin>>value;
			it=last+=value;
		}
	}
	auto const s=pos.back();
	auto const g=std::gcd(s, t);
	std::map<int64_t, std::vector<std::pair<int64_t, int>>> map;
	std::set<int64_t> seen; // mod t

	auto const mod=t/g;
	auto const inverse=inv((mod-(s/g)%mod)%mod, mod);

	for(int i=0; i<number; ++i){
		auto const value=pos[i]%t;
		if(not seen.insert(value).second) continue;

		map[pos[i]%g].push_back({
			multiply((pos[i]/g)%mod, inverse, mod)
				, i
		});
	}

	std::vector<int64_t> result(number);
	for(auto& [_,it]: map){
		std::sort(begin(it), end(it));
		auto last=it.back().first-mod;
		for(auto [value, index]: it){
			result[index]=value-last;
			last=value;
		}
	}

	for(auto& it: result) std::cout<<it<<' ';
	std::cout<<'\n';
}