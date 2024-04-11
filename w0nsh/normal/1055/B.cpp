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

int n, m, l, ans;
std::vector<ll> A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> l;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	bool last = false;
	FOR(i, n){
		if(A[i] > l && !last) ans++;
		if(A[i] > l) last = true;
		else last = false;
	}
	while(m--){
		int what;
		std::cin >> what;
		if(what == 0){
			std::cout << ans << "\n";
		}else{
			int v, x;
			std::cin >> v >> x;
			v--;
			if(A[v] <= l && A[v] + x > l){
				int change = 1;
				if(v > 0 && A[v-1] > l) change--;
				if(v < n-1 && A[v+1] > l) change--;
				ans += change;
			}
			A[v] += x;
		}
	}
	return 0;
}