#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int M = 1e9+7;
 
int mod_pow(int x, int p){
	int r = 1; p += p;
	for(int y=x; p/=2; y=(y*y) % M)
		if(p & 1) r = (r*y) % M;
	return r;
}
 
int inv(int x){
	return mod_pow(x, M-2);
}
 
int frac(int i, int j){
	return (i * inv(j)) % M;
}
 
int num(int i, int j){
	return (i > 0) + (j > 0) * 2;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, m, r, c, x, y, p;
 
		cin >> n >> m >> r >> c >> x >> y >> p;
 
		int h = frac(p, 100);
		int z = frac(100-p, 100);
 
		int dr = 1, dc = 1;
 
		map<int, bool> mp[n+1][m+1];
 
		int ans = 0, timer = 0, k = 0;

		bool oh = 0;

		if(r == x || c == y){
			oh = 1;
		}
 
		vector<array<int, 2>> when; // time, before this
 
		while(1){
			if(!(r + dr) || r + dr > n) dr = -dr;
			if(!(c + dc) || c + dc > m) dc = -dc;
			r += dr, c += dc;

			bool &vis = mp[r][c][num(dr, dc)];

			if(vis) break;

			if(r == x || c == y){
				when.push_back({timer, k});
				++k;
			}
			vis = 1;
			timer++;
		}
 
		for(auto &[time, bef] : when){
			int mul = h * mod_pow(z, bef);
			mul %= M;
 
			++time;
 
			int a_ = time;
			int d_ = timer;
			int r_ = mod_pow(z, k);
 
			int deno = (1LL - r_ + M) % M;
 
			int add = frac(a_, deno) + frac((d_ * r_) % M, (deno * deno) % M);
 
			(add *= mul) %= M;
			// cout << a_ << ' ' << deno << '\n';
			// cout << time << ' ' << bef << '\n';
			(ans += add) %= M;
		}

		ans %= M;
		ans += M;
		ans %= M;

		if(oh) {
			(ans *= z) %= M;
		}
		ans %= M;
		ans += M;
		ans %= M;
 
		cout << ans << '\n';
	}
}