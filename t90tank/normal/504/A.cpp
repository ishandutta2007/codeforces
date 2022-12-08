#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std; 

const int maxn = 500000; 

int s[maxn]; 
int degree[maxn];
int n,m;
int a[maxn],b[maxn];  
vector<int> Q; 

int main() 
{
	scanf( "%d", &n ); 
	for (int i = 0; i < n; ++i) 
	{
		scanf( "%d%d", &degree[i], &s[i] ); 
		if ( degree[i] == 1 ) Q.push_back( i ); 
	}
	while ( !Q.empty() ) 
	{
		int u = Q.back(); 
		Q.pop_back(); 
		if ( degree[u] == 1 )
		{
			m++; 
			a[m] = u; b[m] = s[u]; 
			degree[u]--; degree[b[m]]--; 
			s[b[m]] ^= u; 
			s[u] = 0; 
			if ( degree[b[m]] == 1 ) Q.push_back( b[m] ); 
		} 
	}
	printf( "%d\n", m ); 
	for (int i = 1; i <= m; ++i) printf( "%d %d\n", a[i], b[i] ); 
}