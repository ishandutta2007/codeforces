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

int n, deg;
std::vector<PII> A;
std::vector<VI> g;
std::vector<int> leafs;
int ans;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a;
		std::cin >> a;
		deg += a;
		if(a == 1) leafs.push_back(i);
		else A.push_back(MP(a, i));
	}
		g.resize(n);
	if(deg < (n-1)*2){
		std::cout << "NO\n";
		return 0;
	}
	std::sort(A.begin(), A.end(), std::greater<PII>());
	while(SZ(leafs) < 2){
		leafs.push_back(A.back().Y);
		A.pop_back();
	}
	int left = leafs.back();
	leafs.pop_back();
	int right = leafs.back();
	leafs.pop_back();
	int ans = 0;
	while(SZ(A) > 1){
		g[A.back().Y].push_back(left);
		ans++;
		while(!leafs.empty() && A.back().X > 2){
			g[leafs.back()].push_back(A.back().Y);
			leafs.pop_back();
			A.back().X--;
		}
		left = A.back().Y;
		A.pop_back();
	}
	g[right].push_back(A.back().Y);
	g[A.back().Y].push_back(left);
	ans += 2;
	while(!leafs.empty() && A.back().X > 2){
		g[leafs.back()].push_back(A.back().Y);
		leafs.pop_back();
		A.back().X--;
	}
	std::cout << "YES " << ans << "\n";
	std::cout << n-1 << "\n";
	FOR(i, n) TRAV(ch, g[i]) std::cout << i+1 << " " << ch+1 << "\n";
	return 0;
}