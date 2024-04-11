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

const int MOD = 1000000007;
int n, q;
VI pref;
VI pows;

int ans(int zer, int jed){
	int first = pows[jed]-1;
	if(first == -1) first = MOD-1;
	int sec = (1ll*first*(pows[zer]-1))%MOD;
	return (first+sec)%MOD;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	pows.push_back(1);
	FOR(i, 1000006) pows.push_back((2ll*pows[i])%MOD);
	pref.resize(n+1);
	pref.push_back(0);
	FOR(i, n){
		char a;
		std::cin >> a;
		pref[i+1] = pref[i] + (a == '1' ? 1 : 0);
	}
	while(q--){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		int jed = pref[b+1]-pref[a];
		int zer = (b-a+1)-jed;
		std::cout << ans(zer, jed) << "\n";
	}
	return 0;
}