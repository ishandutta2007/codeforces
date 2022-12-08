#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 2000000; 

ll n, m, a, P, Q; 
ll inv[maxn], fac[maxn], ifac[maxn]; 
ll ans[maxn], q[maxn]; 

ll C(int a, int b) {
	if (a < b) return 0; 
	return fac[a] * ifac[b] % P * ifac[a-b] % P; 
}

int main() {
	cin>>n>>m>>a>>Q; 
	q[0] = 1; 
	for (int i = 1; i < maxn; ++i) {
		q[i] = q[i-1] * a % Q; 
		if (q[i] == 1) {
			P = i; 
			break; 
		}
	}
	
	inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1; 
	for (int i = 2; i < maxn; ++i) {
		inv[i] = P / i * (P - inv[P % i]) % P; 
		fac[i] = fac[i-1] * i % P; 
		ifac[i] = ifac[i-1] * inv[i] % P;
	}
	ans[0] = 1; 
	for (int i = 1; i < n; ++i) 
		ans[i] = (ans[i-1] + C(m,i)) % P;
		
	for (int i = n-1; i >= 0; --i) printf( "%lld ", q[ans[i]] ); 
	puts( "" ); 
}