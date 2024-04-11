#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int a, b;
std::set<int> set;
std::set<int> ansa;
bool swapped = false;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> a >> b;
	if(a > b) std::swap(a, b), swapped = true;
	if(a == b && b == 0){
		std::cout << "0\n0\n";
		return 0;
	}
	int sum = 0;
	int cur = 1;
	while(sum + cur <= a+b){
		set.insert(cur);
		sum += cur;
		cur++;
	}
	sum = 0;
	auto it = set.end();
	do{
		it--;
		cur = *it;
		if(a - cur >= 0){
			a -= cur;
			ansa.insert(cur);
		}
	}while(it != set.begin());
	if(swapped){
		std::cout << SZ(set)-SZ(ansa) << "\n";
		TRAV(i, set) if(ansa.count(i) == 0) std::cout << i << " ";
		std::cout << "\n";
		std::cout << SZ(ansa) << "\n";
		TRAV(i, ansa) std::cout << i << " ";
	}else{
		std::cout << SZ(ansa) << "\n";
		TRAV(i, ansa) std::cout << i << " ";
		std::cout << "\n";
		std::cout << SZ(set)-SZ(ansa) << "\n";
		TRAV(i, set) if(ansa.count(i) == 0) std::cout << i << " ";
	}
	return 0;
}