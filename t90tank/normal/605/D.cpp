#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct data {
	int left, right; 
	vector<int> val; 
}e[3000000]; 

const int maxn = 200000; 
const int oo = 1000000007; 

int tot; 
int n; 
int a[maxn], b[maxn], c[maxn], d[maxn], F[maxn], fa[maxn], no[maxn];
deque<int> Q; 
bool v[maxn]; 

void Ins( int &T, int l, int r, int num ) 
{
	if ( T == 0 ) 
	{ T = ++tot; e[T] = e[0]; }
	e[T].val.push_back( num ); 
	if ( l == r ) return; 
	int m = ( l + r ) / 2; 
	if ( a[num] <= m ) Ins( e[T].left, l, m, num ); 
	else Ins( e[T].right, m+1, r, num );  
}

void Find( int &T, int l, int r, int num ) 
{ 
	if ( c[num] >= r ) {
		while ( !e[T].val.empty() && b[e[T].val.back()] <= d[num] ) 
		{
			int u = e[T].val.back();
			if ( v[u] ) 
			{ F[u] = F[num] + 1; v[u] = false; Q.push_back( u ); fa[u] = num; }
			e[T].val.pop_back(); 
		}
		return;
	} 
	int m = ( l + r ) / 2; 
	Find( e[T].left, l, m, num ); 
	if ( c[num] > m ) Find( e[T].right, m+1, r, num ); 
}

bool cmp( int x, int y ) 
{ return b[x] > b[y]; }

int main() 
{
	scanf( "%d", &n ); 
	a[0] = b[0] = c[0] = d[0] = 0; 
	for (int i = 1; i <= n; ++i) 
	{
		scanf( "%d%d%d%d", &a[i], &b[i], &c[i], &d[i] ); no[i] = i;
	}
	tot = 0; 
	memset( e, 0, sizeof( e ) ); 
	sort( no, no+n+1, cmp ); 
	int tree = 0; 
	for (int i = 0; i <= n; ++i) Ins( tree, 0, oo, no[i] ); 
	memset( v, true, sizeof( v ) ); 
	Q.push_back( 0 ); F[0] = 0; v[0] = false; 
	while ( !Q.empty() ) 
	{
		int u = Q.front(); 
		Q.pop_front(); 
		Find( tree, 0, oo, u ); 
	}
	if ( v[n] ) printf( "-1\n" ); 
	else {
		int x = n; 
		vector<int> P; 
		while ( x != 0 ) 
		{ P.push_back( x ); x = fa[x]; }
		printf( "%d\n", F[n] ); 
		for (int i = F[n]-1; i > 0; --i) printf( "%d ", P[i] ); 
		printf( "%d\n", n ); 
	}
}