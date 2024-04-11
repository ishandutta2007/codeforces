#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1e9+7;

struct nCr {
	vector<int> F, invF;
	nCr(int MX) : F(MX), invF(MX) {
		F[0] = 1;
		for(int i=1; i<MX; ++i) {
			F[i] = (i * F[i-1]) % M;
		}
		invF[MX-1] = mod_pow(F[MX-1], M-2);
		for(int i=MX; --i; ){
			invF[i-1] = (i * invF[i]) % M;
		}
	}
	int mod_pow(int x, int p) {
		int r = 1; p += p;
		for(int y=x; p/=2; y=(y*y) % M)
			if(p & 1) r = (r*y) % M;
		return r;
	}
	int operator()(int a, int b){
		if(b < 0 || a < b) return 0;
		return (F[a] * ((invF[b] * invF[a-b]) % M)) % M;
	}
};

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	++n;

	nCr ncr(1e6);

	int a[n]; for(int &i : a) cin >> i;

	int ans {};
	for(int i = 0; i < n; ++i) {
		ans += ncr(a[i]+i, i+1);
		ans %= M;
	}
	cout << ans;
}