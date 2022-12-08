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

int main() 
{
	scanf( "%d%d", &n, &k ); 
	if ( k > n / 2 ) k = n / 2; 
	long long ans = 0; 
	for (int i = 1; i <= n; ++i) 
		if ( i <= k ) ans += (n-i); 
		else if ( i > k ) ans += min( k, n-i ); 
	cout<<ans<<endl; 
}