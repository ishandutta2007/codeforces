#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	ll ans = 0;
	VI nxt(n);
	nxt[n-1] = n;
	for(int i = n-2; i >= 0; --i){
		nxt[i] = (A[i+1] == 1 ? nxt[i+1] : i+1);
	}
	FOR(i, n){
		if(A[i] == 1) continue;
		if(A[i] >= n+2){
			ans += A[i] - (n+2);
			A[i] = n+2;
		}
		while(A[i] > 1){
			ans++;
			ll pos = i;
			while(pos < n){
				ll jmp = pos + A[pos];
				bool was = false;
				if(A[pos] > 1){
					A[pos]--;
					was = true;
				}
				if(A[pos] == 1 && was){
					FOR(j, pos) if(nxt[j] == pos) nxt[j] = nxt[pos];
				}
				pos = jmp;
				if(pos < n && A[pos] == 1) pos = nxt[pos];
			}
		}
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}