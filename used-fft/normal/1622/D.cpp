#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18, M = 998244353;

struct nCr{
	vector<int> F, invF;
	nCr(int MX) : F(MX), invF(MX) {
		F[0] = 1;
		for(int i=1; i<MX; ++i){
			F[i] = (i * F[i-1]) % M;
		}
		invF[MX-1] = mod_pow(F[MX-1], M-2);
		for(int i=MX; --i; ){
			invF[i-1] = (i * invF[i]) % M;
		}
	}
	int mod_pow(int x, int p){
		int r = 1; p += p;
		for(int y=x; p/=2; y=(y*y) % M)
			if(p & 1) r = (r*y) % M;
		return r;
	}
	int operator()(int a, int b){
		if(b < 0 || a < b) return 0;
		return (F[a] * ((invF[b] * invF[a-b]) % M)) % M;
	}
} C(100000);

int n, k, res = 1, total;
bitset<5001> s;

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	cin >> s;

	for(int i=0; i<n; ++i){
		int curr = 0;
		total += s[i];
		for(int j=i; j<n; ++j){
			curr += s[j];
			if(curr > k) break;
			if(i == j) continue;

			if(s[i] && s[j]){
				res += C(j - i - 1, curr);
			}else if(s[i] ^ s[j]){
				res += C(j - i - 1, curr - 1);
			}else{
				res += C(j - i - 1, curr - 2);
			}

			res %= M;
		}
	}

	if(total < k) res = 1;

	cout << (res + M) % M;
}