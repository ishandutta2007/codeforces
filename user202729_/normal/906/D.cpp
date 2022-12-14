// Main test failed. :(
// [I didn't view any test cases.]

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

auto factorize(int number){
	std::vector<std::pair<int, int>> result;
	if(number%2==0){
		result.push_back({2, __builtin_ctz(number)});
		number>>=__builtin_ctz(number);
	}
	for(int prime=3;prime*prime<=number;prime+=2) if(number%prime==0) {
		result.push_back({prime, 0});
		do{
			number/=prime;
			++result.back().second;
		}while(number%prime==0);
	}
	if(number!=1) result.push_back({number, 1});
	return result;
}

int phi(int number){
	for(auto [prime,_]: factorize(number))
		number=number/prime*(prime-1);
	return number;
}


int binPow(int a, int exp, int mod) {
	assert(mod!=1);
	int ans = 1;
	for (; exp; exp /= 2, a = int((int64_t)a*a%mod))
		if (exp&1) ans = int(ans*(int64_t)a%mod);
	return ans;
}

auto const LIMIT=100;

int solve(auto left, auto right, auto mod){
	// output some number congruent to power tower (left... right) mod mod >= LIMIT,
	// but if the result is < LIMIT then output its exact value
	assert(std::find(left, right, 1)==right);

	assert(left!=right);
	if(left+1==right) return *left;
	if(*mod==1){
		if(right-left>=4 or *left>=LIMIT) return LIMIT; // 2^2^2^2 == 65536
		else {
			auto exp=solve(left+1, right, mod);
			if(exp>=LIMIT) return LIMIT;
			else return (int)std::round(std::min((double)LIMIT, std::pow((double)*left, exp)));
		}
	}

	assert(phi(*mod)==mod[1]);
	auto temp=solve(left+1, right, mod+1);
	if(*left<LIMIT and temp<10 // 2^10 > LIMIT
			){
		auto x=std::round(std::pow((double)*left, temp));
		if(x<LIMIT) return (int)x;
	}
	auto result=binPow(*left, temp, *mod);

	if(result<LIMIT){
		assert(*mod<=1000000000); // so the addition cannot overflow
		result+=(LIMIT/ *mod+1)* *mod;
		assert(result>=LIMIT);
	}
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, mod;
	std::cin>>number>>mod;

	std::vector<int> modValues{mod};
	while(modValues.back()!=1)
		modValues.push_back(phi(modValues.back()));

	std::vector<int> value(number); 
	for(auto & item: value) std::cin>>item;

	std::vector<int> next1Position(number);
	for(auto index=(int)value.size(), next=(int)value.size(); index--;){
		assert(value[index]!=0);
		if(value[index]==1) next=index;
		next1Position[index]=next;
	}

	int numQuery; std::cin>>numQuery;
	while(numQuery--){
		int left, right; std::cin>>left>>right;--left;
		if(value[left]==1) {
			std::cout<<1%mod<<"\n";
			continue;
		}
		right=std::min(right, next1Position[left]);
		std::cout<<solve(begin(value)+left, begin(value)+right, begin(modValues))%mod<<'\n';
	}
}