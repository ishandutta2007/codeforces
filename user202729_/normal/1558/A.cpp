//... probably undefined behavior
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int awin; std::cin>>awin;
	int bwin; std::cin>>bwin;
	int const n=awin+bwin;
	using L=std::initializer_list<std::pair<int, int>>;
	std::vector<int> result;

	L L_even{{n/2, n/2}};
	L L_odd{{n/2+1, n/2}, {n/2, n/2+1}};
	for(auto [aserve, bserve]: n%2==0 ? L_even: L_odd){
		int const minimum=std::abs(awin-aserve);
		int const maximum=std::min(awin+aserve, bwin+bserve);
		assert(minimum%2==maximum%2);

		std::vector<int> result1;
		for(int i=minimum; i<=maximum; i+=2) result1.push_back(i);

		std::vector<int> result2(result.size()+result1.size());
		std::merge(begin(result), end(result),begin(result1), end(result1), result2.begin());
		result=std::move(result2);

	}
	// print result
	std::cout<<(int)result.size()<<'\n';
	for(auto const& it: result){
		std::cout<<it<<' ';
	}
	std::cout<<'\n';
}