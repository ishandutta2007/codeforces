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

const int maxn = 200000; 

int a[maxn], b[maxn]; 
int ind[maxn]; 
vector<int> ah[maxn]; 
int n, m; 

bool check( int t ) 
{
	memset( ind, 0, sizeof( ind ) ); 
	for (int i = 1; i <= n; ++i) ah[i].clear(); 
	for (int i = 1; i <= t; ++i) 
	{ ind[b[i]]++; ah[a[i]].push_back( b[i] ); }
	int k = -1; 
	for (int i = 1; i <= n; ++i) 
		if ( ind[i] == 0 )
			if ( k != -1 ) return false; 
			else k = i; 
	for (int i = 1; i <= n; ++i) 
	{
		int u = k; 
		k = -1; 
		for (int j = 0; j < ah[u].size(); ++j)
		{
			ind[ah[u][j]]--; 
			if ( ind[ah[u][j]] == 0 ) 
				if ( k != -1 ) return false; 
				else k = ah[u][j]; 
		}
	}
	return true; 
}

int main() 
{
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= m; ++i) 
		scanf( "%d%d", &a[i], &b[i] ); 
	int l = 0, r = m+1; 
	while ( l + 1 < r ) 
	{
		int temp = ( l + r ) / 2; 
		if ( check( temp ) ) r = temp; 
		else l = temp; 
	}
	if ( r == m + 1 ) cout<<-1<<endl; 
	else cout<<r<<endl; 
}