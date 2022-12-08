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

int n, k; 
char st[1000000]; 
int p[1000000]; 
int l, r, m; 

int Abs( int x ) 
{ return max( x,-x ); }

int Calc( int m ) 
{ return max( Abs(p[l]-p[m]), Abs(p[r]-p[m]) ); }

int main() 
{
	scanf( "%d%d", &n, &k ); 
	scanf( "%s", st ); 
	int s = 0; 
	for (int i = 0; i < n; ++i) 
		if ( st[i] == '0' ) p[++s] = i; 
	l = 1, r = k+1, m = 1; 
	while ( m < r && Calc(m+1) <= Calc(m) ) m++; 
	int ans = Calc( m ); 
	for (l = 2; l+k<=s; ++l) 
	{
		r = l+k; 
		if ( m < l ) m = l; 
		while ( m < r && Calc(m+1) <= Calc(m) ) m++; 
	//	cout<<l<<' '<<r<<' '<<m<<' '<<Calc(m)<<endl; 
		ans = min( ans, Calc(m) ); 
	}
	cout<<ans<<endl; 
}