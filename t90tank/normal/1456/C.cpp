#include <bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
using namespace std; 
using ll = long long;

const int maxn = 500006; 
const int maxd = 1000006; 

int n, k; 
int c[maxn]; 
int s_[maxd*2]; 
ll a[maxn]; 
int *s; 
int tot; 

int main() {
	s = &s_[maxd]; 
	scanf( "%d%d", &n, &k ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &c[i] ); 
	for (int i = 1; i <= n; ++i) s[c[i]]++; 
	s_[0] = 0; 
	for (int i = 1; i < maxd*2; ++i) s_[i] += s_[i-1]; 
	for (int i = 1; i <= n; ++i) a[s[c[i]]--] = c[i]; 
	ll ans = 0; 
	if (a[n] >= 0) {
		tot = 1;
		for (int i = n; i > 1; --i) {
			if (a[i] + a[i-1] >= 0) {
				ans += a[i];
				a[i-1] += a[i]; 
			}
			else {
				ans += a[i];
				a[i-1] += a[i]; 
				tot = i-1;
				break; 
			}
		}
	}
	else tot = n;  
	k++; 
	for (int i = 1; i <= tot; ++i) 
		ans += a[i] * ll((i+k-1) / k-1); 
	printf( "%lld\n", ans ); 
}