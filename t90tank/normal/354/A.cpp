#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std; 

const int maxn = 200000; 

int n,l,r,ql,qr; 
int w[maxn]; 

int main() 
{
	scanf( "%d%d%d%d%d", &n, &l, &r, &ql, &qr ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &w[i] ); 
	int sum = 0; 
	for (int i = 1; i <= n; ++i) sum += r * w[i]; 
	int ans = sum+n*qr; 
	for (int i = 0; i <= n; ++i) 
	{
		if ( i != 0 ) sum += l*w[i]-r*w[i]; 
		if ( i >= n-i ) ans = min( ans, sum + max(0,i-(n-i)-1) * ql ); 
		else ans = min( ans, sum + (max(0,n-i-i-1)) * qr ); 
	}
	cout<<ans<<endl; 
}