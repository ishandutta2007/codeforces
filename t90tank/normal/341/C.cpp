#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod = 1000000007; 
const int maxn = 2006; 
int n; 
bool v[maxn]; 
int a[maxn];
ll c[maxn][maxn];  

ll cal( int k ) 
{ 
	if ( k <= 1 ) return 1;
	return k*cal(k-1)%mod; 
}

int main() 
{
	memset( v, true, sizeof( v ) ); 
	scanf( "%d", &n );  
	for (int i = 1; i <= n; ++i) 
	{ scanf( "%d", &a[i] ); if ( a[i] != -1 ) v[a[i]] = false; }
	int p = 0, q = 0; 
	for (int i = 1; i <= n; ++i) 
		if ( v[i] ) 
			if ( a[i] == -1 ) p++; 
			else q++;
	memset( c, 0, sizeof( c ) ); 
	c[0][0] = 1; 
	for (int i = 1; i <= n; ++i) 
	{
		c[i][0] = 1; 
		for (int j = 1; j <= n; ++j) 
			c[i][j] = ( c[i-1][j-1] + c[i-1][j] ) % mod; 
	}
	ll ans = cal( p + q ); 
	for (int i = 1; i <= p; ++i)
	{
		ll tmp = -1; 
		if ( i % 2 == 0 ) tmp = 1; 
		ans = ( ( ans + tmp * c[p][i] % mod * cal(p+q-i) ) % mod + mod ) % mod;  
	}
	cout<<ans<<endl; 
}