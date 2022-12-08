#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std; 

const int maxn = 2000000; 

vector<int> a[maxn]; 
int n, k, s; 
int add[maxn];   
int r[maxn], sum[maxn]; 

int main() 
{
	scanf( "%d%d", &n, &k );
	s = 1; 
	int ans1 = k+1;  
	for (int i = 1; i <= n; ++i) 
	{
		scanf( "%d", &r[i] );
		add[max(r[i]-k,0)]++; 
		add[r[i]+1]--; 	
		s = max( s, r[i] ); 
		ans1 = min( ans1, r[i] ); 
	}
	if ( ans1 < k+1 ) 
	{ cout<<ans1<<endl; return 0; }
	sum[0] = add[0]; 
	for (int i = 1; i <= s; ++i) sum[i] = sum[i-1] + add[i]; 
	int ans = k+1; 
	for (int i = k+1; i <= s; ++i) 
	{
		int ac = 0; 
		for (int j = i; j <= s; j+=i) 
			ac += sum[j]; 
		if ( ac >= n ) ans = i; 
	}
	cout<<ans<<endl; 
}