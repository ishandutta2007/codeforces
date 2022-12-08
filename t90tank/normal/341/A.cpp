#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10000007;

typedef long long ll;  

int a[maxn];  
ll p, q; 
int n;
long long sum; 

ll gcd( ll a, ll b ) 
{ 
	if ( b == 0 ) return a; 
	return gcd( b, a % b ); 
}

int main() 
{
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	sort( a+1, a+n+1 );
	sum = a[1]; 
	p = 0; q = n;   
	for (int i = 2; i <= n; ++i)
	{ p = p + ll(i-1)*a[i] - sum; sum += a[i]; }
	p = p * 2 + sum; 
	ll r = gcd( p, q ); 
	cout<<p/r<<' '<<q/r<<endl; 
}