#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 
const ll mod = 1000000007; 
const int D = 20; 

int f[76][(1<<D)]; 
int n; 
char s[100]; 

bool check(ll x) {
	if (x == 0) return false; 
	x++; 
	return (x & (-x)) == x; 
}

void Add(int &a, ll b) {
	a = (ll(a) + b) % mod; 
}

int main() {
	scanf( "%d", &n ); 
	scanf( "%s", s+1 ); 
	memset(f, 0, sizeof(f) ); 
	int ans = 0; 
	for (int i = 0; i <= n; ++i) {
		Add(f[i][0], 1); 
		for (int msk = 0; msk < (1<<D); ++msk) 
			if (f[i][msk] > 0) {
				//cout<<i<<' '<<msk<<' '<<f[i%W][msk]<<endl; 
				if (check(msk)) Add( ans, f[i][msk] ); 
				int t = 0; 
				for (int j = 1; i + j <= n; ++j) {
					t = t * 2 + s[i+j]-'0'; 
					if (t > D) break; 
					if (t != 0)
						Add( f[(i+j)][msk|(1<<(t-1))], f[i][msk] ); 
				}
			}
	}
	cout<<ans<<endl; 
}