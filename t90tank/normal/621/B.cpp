#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std; 

int n; 
int s1[3000];
int s2[3000];  

int main() 
{
	scanf( "%d", &n ); 
	memset( s1, 0, sizeof( s1 ) ); 
	memset( s2, 0, sizeof( s2 ) ); 
	for (int i = 1; i <= n; ++i) 
	{
		int x, y; 
		scanf( "%d%d", &x, &y ); 
		s1[x+y]++; 
		s2[x-y+1000]++;  
	}
	long long ans = 0; 
	for (int i = 1; i <= 2500; ++i) 
	{
		ans += (long long)s1[i]*(s1[i]-1)/2; 
		ans += (long long)s2[i]*(s2[i]-1)/2; 
	}
	cout<<ans<<endl; 
}