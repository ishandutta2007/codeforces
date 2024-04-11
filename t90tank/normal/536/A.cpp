#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std; 

int a,b,n,l,t,m; 
long long A, B; 

int main() 
{
	scanf( "%d%d%d", &a, &b, &n );
	A = a; B = b;  
	for (int i = 1; i <= n; ++i) 
	{
		scanf( "%d%d%d", &l, &t, &m );
		if ( A+(l-1)*B > t ) printf( "-1\n" ); 
		else {
			int L = l, R = (t-A)/B + 2; 
			while ( L + 1 < R )
			{
				int M = ( L + R ) / 2; 
				if ( ((long long)(l-1+M-1))*(M-l+1)/2*B + A*(M-l+1) <= ((long long)m) * t ) L = M; 
				else R = M; 
			}
			printf( "%d\n", L ); 
		}
	}
}