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

int n;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i] += 1000000;
	std::cout << n+1 << "\n";
	std::cout << 1 << " " << n << " " << 1000000 << "\n";
	int bigger = -1;
	FOR(i, n){
		int cur = std::max(1, i);
		int mncur = 1000000000;
		int mn = 1000000000;
		while(cur < 10000){
			if(A[i]%cur > bigger && A[i]%cur < mn){
				mn = A[i]%cur;
				mncur = cur;
			}
			cur++;
		}
		std::cout << 2 << " " << i+1 << " " << mncur << "\n";
		bigger = mn;		
	}
	return 0;
}