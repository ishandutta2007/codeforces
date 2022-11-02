#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, m, r, c, x, y;
		cin >> n >> m >> r >> c >> x >> y;

		int dr = 1, dc = 1;

		int res = 0;

		while(1){
			if(r == x || c == y) break;

			if(r + dr > n || !(r + dr)) dr = -dr;
			if(c + dc > m || !(c + dc)) dc = -dc;

			r += dr;
			c += dc;


			res++;
		}

		cout << res << '\n';
	}
}