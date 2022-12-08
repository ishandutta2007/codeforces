#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second 

const ll mod = 1000000007; 
const int maxn = 500; 

int n; 
ll f[maxn][maxn*3]; 

void ud(ll &a, ll b) {
	(a += b) %= mod; 
}

ll C(ll x) {
	if (x == 0) return 0; 
	return x * (x-1) / 2 % mod; 
}

int main() {
	cin>>n; 
	memset(f, 0, sizeof(f) ); 
	f[1][0] = f[1][1] = 1; 
	for (int i = 1; i < n; ++i) {
		for (int l = 0; l+i-1 <= n; ++l) 
			for (int r = 0; r+i-1 <= n; ++r) {
				ll x = f[i][l] * f[i][r] % mod; 
				ud(f[i+1][l+r], x*(1+l*2+r*2)); 
				ud(f[i+1][l+r+1], x); 
				ud(f[i+1][l+r-1], x*C(l+r)*2); 
			}
	}
	cout<<f[n][1]<<endl; 
}