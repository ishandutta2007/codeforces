#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map> 
using namespace std;

map<int,int> X; 
map<int,int> Y; 
map<pair<int,int>, int> S; 

int main() 
{
	int n; 
	scanf( "%d", &n ); 
	int x, y; 
	long long ans = 0; 
	for (int i = 1; i <= n; ++i) 
	{
			scanf( "%d%d", &x, &y ); 
			ans += X[x]; X[x]++;
			ans += Y[y]; Y[y]++;
			ans -= S[make_pair(x,y)]; 
			S[make_pair(x,y)]++;
	}
	cout<<ans<<endl; 
}