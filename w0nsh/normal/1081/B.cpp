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
std::vector<PII> A;
VI ans;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(MP(a, i));
	}
	ans.resize(n);
	std::sort(A.begin(), A.end());
	int hat = 1;
	while(!A.empty()){
		auto cur = A.back();
		A.pop_back();
		int left = n-cur.X;
		ans[cur.Y] = hat;
		while(--left){
			if(A.empty() || A.back().X != cur.X){
				std::cout << "Impossible\n";
				return 0;
			}
			ans[A.back().Y] = hat;
			A.pop_back();
		}
		hat++;
	}
	std::cout << "Possible\n";
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}