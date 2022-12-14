#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
#include<list>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int n, k; std::cin>>n>>k;

	std::list<int> a;
	std::vector<std::list<int>::iterator> iterator(n);
	for(int _=0; _<n; ++_){
		int value; std::cin>>value;
		--value;
		a.push_back(value);
		iterator[value]=std::prev(a.end());
	}

	std::vector<int> b(k);
	std::vector<int> useTime(n, -1);
	for(int index=0; index<k; ++index){
		std::cin>>b[index];
		--b[index];
		assert(useTime[b[index]]<0);
		useTime[b[index]]=index;
	}

	int const MOD=998244353;
	int result=1;
	for(int index=0; index<k; ++index){
		auto const value=b[index];
		auto const it=iterator[value];
		auto const prevCannotDelete=it==a.begin() or useTime[*std::prev(it)]>index;
		auto const nextCannotDelete=std::next(it)==a.end() or useTime[*std::next(it)]>index;
		if(prevCannotDelete and nextCannotDelete){
			std::cout<<"0\n";
			return;
		}else if(prevCannotDelete)
			a.erase(std::next(it));
		else if(nextCannotDelete){
			a.erase(std::prev(it));
		}else{ // both can be deleted, which one doesn't matter
			a.erase(std::prev(it));
			result=result*2%MOD;
		}
	}
	std::cout<<result<<'\n';
}