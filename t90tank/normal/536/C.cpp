#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std; 
typedef long long ll;

const int maxn = 300000; 

struct point 
{
	ll r, s;
	int no;  
}a[maxn]; 

ll xmul(point a, point b, point c) 
{
	return (a.r-b.r)*(a.s-c.s)*c.r*b.s - (a.r-c.r)*(a.s-b.s)*b.r*c.s; 
}

int n; 

bool cmp( const point &a, const point &b ) 
{
	return a.r > b.r || ( a.r == b.r && a.s > b.s ); 
}
map<pair<int,int>, int> S; 
int stack[maxn], top;
int rr[maxn], ss[maxn];  

int main() 
{
	scanf( "%d", &n );
	for (int i = 1; i <= n; ++i)
	{
		scanf( "%d%d", &rr[i], &ss[i] ); 
		a[i].r = rr[i]; a[i].s = ss[i]; a[i].no = i;  
	}
	sort( a+1, a+n+1, cmp ); 
	top = 1; 
	stack[1] = 1; 
	for (int i = 2; i <= n; ++i) 
	{
		if ( a[i].s <= a[stack[top]].s && a[i].r <= a[stack[top]].r ) continue; 
		while ( top > 1 && xmul( a[stack[top-1]], a[stack[top]], a[i] ) < 0 ) top--; 
		stack[++top] = i;   
	}
	for (int i = 1; i <= top; ++i) S[make_pair(a[stack[i]].r, a[stack[i]].s)] = 1;
	bool flag = true;  
	for (int i = 1; i <= n; ++i)
		if ( S.count( make_pair(rr[i], ss[i]) ) > 0 ) 
		{
			if ( flag ) flag = false; else printf( " " ); 
			printf( "%d", i ); 
		}
}