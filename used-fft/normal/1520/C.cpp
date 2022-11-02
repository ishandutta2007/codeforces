#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int g[n][n], odd = 1, even = (n * n + 2) / 2;
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if((i + j) & 1) g[i][j] = odd++;
				else g[i][j] = even++;
			}
		}
		bool ok = true;
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if(i && abs(g[i-1][j]-g[i][j]) == 1) ok = false;
				if(j && abs(g[i][j-1]-g[i][j]) == 1) ok = false;
			}
		}
		if(!ok) cout << -1 << '\n';
		else{
			for(int i=0; i<n; ++i){
				for(int j=0; j<n; ++j)
					cout << g[i][j] << ' ';
				cout << '\n';
			}
		}
	}

}