#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;

const ll mod = 1000000007; 
const int maxn = 2000000;  

ll s[30]; 
int n, k;
char st[maxn]; 
int before[30], next[30]; 

int main() 
{
	scanf( "%d%d", &n, &k ); 
	ll ans = 1; 
	for (int i = 0; i <= k; ++i) 
	{ before[i+1] = i; next[i] = i+1; } 
	for (int i = 1; i <= k; ++i) s[i] = 1; 
	scanf( "%s", st ); 
	int m = strlen( st ); 
	for (int i = 0; i < m; ++i) 
	{
		int x = st[i] - 'a' + 1; 
		ans = ( ans + s[x] ) % mod; 
		for (int j = 1; j <= k; ++j) 
		{
			if ( j != x ) s[j] = ( s[j] + s[x] ) % mod; 
//			cout<<s[j]<<' '; 
		}
//		cout<<endl; 
		next[before[x]] = next[x]; 
		before[next[x]] = before[x]; 
		before[x] = before[k+1]; 
		next[before[k+1]] = x; 
		next[x] = k+1; 
		before[k+1] = x; 
	}
	for (int i = 1; i <= n; ++i) 
	{
		int x = next[0]; 
		ans = ( ans + s[x] ) % mod; 
		for (int j = 1; j <= k; ++j) 
			if ( j != x ) s[j] = ( s[j] + s[x] ) % mod; 
		next[before[x]] = next[x]; 
		before[next[x]] = before[x]; 
		before[x] = before[k+1]; 
		next[before[k+1]] = x; 
		next[x] = k+1; 
		before[k+1] = x; 
	}
	cout<<ans<<endl; 
}