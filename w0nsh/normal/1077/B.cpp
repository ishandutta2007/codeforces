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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	VI A;
	std::cin >> n;
	A.push_back(0);
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	A.push_back(0);
	n += 2;
	int count = 0;
	REP(i, 1, n+1){
		if(A[i] == 0 && A[i-1] == 1 && A[i+1] == 1){
			count++;
			A[i+1] = 0;
		}
	}
	std::cout << count << "\n";
	return 0;
}