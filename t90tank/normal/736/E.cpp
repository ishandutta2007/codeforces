#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 
const int maxn = 3006; 

int n, m; 
int f[maxn][maxn]; 
int a[maxn]; 
int s[maxn]; 
vector<int> Q; 

bool cmp(int x, int y) {
	return ( a[x]-s[x] < a[y]-s[y] ) || ( a[x]-s[x] == a[y]-s[y] && x > y ); 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	memset( f, 0, sizeof( f ) ); 
	for (int i = 1; i <= m; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= n; ++i) s[i] = n-1; 
	for (int i = m+1; i <= n; ++i) 
		if ( s[i] < a[m] ) a[i] = s[i]; 
		else a[i] = a[m]; 
	bool flag = true; 
	for (int i = 1; i <= m; ++i) {
		if ( a[i] < s[i] || a[i] - s[i] > n - i ) {
			flag = false; 
			break; 
		}
		Q.clear(); 
		for (int j = i+1; j <= n; ++j) Q.push_back( j ); 
		sort( Q.begin(), Q.end(), cmp ); 
		for (int j = 0; j < a[i] - s[i]; ++j) {
			f[i][Q[j]] = 1; 
			f[Q[j]][i] = -1; 
			s[Q[j]]--; 
			if ( Q[j] > m && s[Q[j]] < a[m] ) a[Q[j]] = s[Q[j]]; 
		}
	}
	if ( flag ) {
		printf( "yes\n" ); 
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) 
				if ( i == j ) printf( "X" ); 
				else if ( f[i][j] > 0 ) printf( "W" ); 
				else if ( f[i][j] == 0 ) printf( "D" ); 
				else if ( f[i][j] < 0 ) printf( "L" ); 
			printf( "\n" ); 
		}
	}
	else printf( "no\n" ); 
}