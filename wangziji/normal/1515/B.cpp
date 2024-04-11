#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
inline bool check(int x)
{
	int t=sqrt(x);
	if(t*t==x) return 1;
	--t;
	if(t*t==x) return 1;
	t+=2;
	if(t*t==x) return 1;
	return 0;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n&1)
		{
			cout << "NO\n";
			continue;
		 } 
		if((check(n)&&n%2==0)||check(n/2))
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}