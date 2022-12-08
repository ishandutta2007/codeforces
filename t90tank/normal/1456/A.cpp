#include <bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
using namespace std; 
using ll = long long; 

int t; 
char a[100006];
int n, p, k, x, y; 
int s[200006]; 

int main() {
	scanf( "%d", &t ); 
	while (t--) {
		scanf( "%d%d%d", &n, &p, &k ); 
		scanf( "%s", a ); 
		for (int i = n-1; i >= 0; --i) {
			int tmp;
			if (a[i] == '0') tmp = 1;
			else tmp = 0; 
			s[i] = i+k<n? s[i+k]+tmp:tmp; 
		}
		scanf( "%d%d", &x, &y ); 
		ll ans = ll(x) * n; 
		for (int i = 0; i + p - 1 < n; ++i) 
			ans = min(ans, s[i+p-1] * ll(x) + ll(y) * i); 
		printf( "%lld\n", ans ); 
	}
}