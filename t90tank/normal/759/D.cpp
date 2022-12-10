#include <bits/stdc++.h>
using namespace std;
const int maxn = 5006;
typedef long long ll; 
const ll mod = 1000000007; 

int u[30]; 
char s[maxn]; 
int b[maxn]; 
int f[maxn][maxn]; 
int g[maxn][maxn]; 
int n; 

int main() {
	scanf( "%d", &n ); 
	scanf( "%s", s+2 ); 
	for (int i = 0; i < 26; ++i) u[i] = 0;  
	for (int i = 2; i <= n+1; ++i) {
		b[i] = u[s[i]-'a']; 
		u[s[i]-'a'] = i; 
	}
	g[1][0] = 1; 
	for (int i = 2; i <= n+1; ++i) {
		g[i][0] = 1; 
		for (int j = 1; j <= i-1; ++j) 
			if (b[i]==0) g[i][j] = ((ll)g[i-1][j-1]+g[i-1][j]) % mod; 
			else g[i][j] = ((ll)g[i-1][j-1]-g[b[i]][j-1]+g[i-1][j]) % mod; 
	}
	f[1][1] = 1;  
	for (int i = 2; i <= n; ++i) {
		f[i][1] = 1; 
		for (int j = 2; j <= n; ++j) 
			f[i][j] = (f[i-1][j]+f[i-1][j-1]) % mod; 
	}
	ll ans = 0; 
	for (int i = 1; i <= n; ++i) {
		ans = (ans+(ll)f[n][i]*g[n+1][i]) % mod; 
	//	cout<<f[n][i]<<' '<<g[n+1][i]<<endl; 
	}
	cout<<(ans+mod)%mod<<endl; 
}