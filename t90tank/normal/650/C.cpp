#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map> 
#include <vector>
using namespace std;

const int maxn = 1000006; 

map<int,int> s1[maxn];
map<int,int> s2[maxn];
int n, m; 
int father[maxn];
vector<pair<int,int> > a1[maxn],a2[maxn];  
vector<int> ah[maxn]; 
int ans[maxn]; 

int getfather( int v ) 
{
	if ( father[v] == v ) return v; 
	father[v] = getfather( father[v] ); 
	return father[v]; 
}

void Link( int x, int y ) 
{
	int fx = getfather( x ); 
	int fy = getfather( y );
	father[fx] = fy;  
}

int ind[maxn]; 

void build( int x, int y ) 
{
	ah[x].push_back( y ); 
	ind[y]++; 
}

int main() 
{
	scanf( "%d%d", &n, &m ); 
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
		{
			father[i*m+j] = i*m+j; 
			int x; 
			scanf( "%d", &x ); 
			if ( s1[i].count( x ) != 0 ) Link( s1[i][x], i*m+j ); 
			s1[i][x] = i*m+j;  
			if ( s2[j].count( x ) != 0 ) Link( s2[j][x], i*m+j ); 
			s2[j][x] = i*m+j; 
			a1[i].push_back( make_pair( x, i*m+j ) ); 
			a2[j].push_back( make_pair( x, i*m+j ) ); 
		} 
	for (int i = 0; i < n; ++i) 
	{
		sort( a1[i].begin() , a1[i].end() ); 
		for (int j = 1; j < m; ++j) 
			if ( a1[i][j-1].first != a1[i][j].first ) 
				build( getfather( a1[i][j-1].second ) , getfather( a1[i][j].second ) );  
	} 
	for (int i = 0; i < m; ++i) 
	{
		sort( a2[i].begin(), a2[i].end() );
		for (int j = 1; j < n; ++j) 
			if ( a2[i][j-1].first != a2[i][j].first ) 
				build( getfather( a2[i][j-1].second ) , getfather( a2[i][j].second ) );  
	}
	vector<int> p, q; 
	for (int i = 0; i < n*m; ++i) 
		if ( ind[getfather(i)] == 0 ) p.push_back( i );
	int tot = 0;  
	while ( !p.empty() ) 
	{
		tot++; 
		q.clear(); 
		for (int i = 0; i < p.size(); ++i)
		{
			int u = p[i]; 
			ans[u] = tot; 
			for (int j = 0; j < ah[u].size(); ++j)
			{ 
				ind[ah[u][j]]--;
				if ( ind[ah[u][j]] == 0 ) q.push_back( ah[u][j] ); 
			}
		}
		p = q; 
	}
	for (int i = 0; i < n; ++i)
	{ 
		for (int j = 0; j < m-1; ++j) 
			 printf( "%d ", ans[getfather(i*m+j)] ); 
		printf( "%d\n", ans[getfather(i*m+m-1)] ); 
	}
}