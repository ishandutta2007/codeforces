#include <bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
using namespace std; 
using ll = long long;

const int maxn = 100006; 

int n; 
int a[maxn]; 
int s[maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	
	for (int i = 1; i < n; ++i) {
		int t = (a[i] ^ a[i+1]); 
		if (i != 1 && t < a[i-1]) {
			printf( "1\n" ); return 0; 
		}
		if (i+2 <= n && t > a[i+2]) {
			printf( "1\n" ); return 0; 
		}
	}
	s[0] = 0; 
	for (int i = 1; i <= n; ++i) s[i] = (s[i-1] ^ a[i]); 
	int ans = n+1; 
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= i; ++j) 
			for (int k = i+1; k <= n; ++k) 
				if ((s[i]^s[j-1]) > (s[i]^s[k]))
					ans = min(ans, i-j + k-i-1);
	}
	if (ans == n+1) printf( "-1\n" ); 
	else printf( "%d\n", ans ); 
}