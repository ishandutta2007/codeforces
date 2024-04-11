#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int N = 100, K = 10000;

bool g[N+1][N+1][K+1];

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	g[1][1][0] = true;

	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			if(i>1){
				for(int k=j; k<=K; ++k){
					g[i][j][k] |= g[i-1][j][k-j];
				}
			}
			if(j>1){
				for(int k=i; k<=K; ++k){
					g[i][j][k] |= g[i][j-1][k-i];
				}
			}
		}
	}

	int T; cin >> T;
	while(T--){
		int n, m, k; cin >> n >> m >> k;
		cout << (g[n][m][k] ? "YES" : "NO") << '\n';
	}
}