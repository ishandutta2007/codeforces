#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	vector<int> a(n),b(m);
	for(int &x:a) scanf("%i",&x);
	sort(a.begin(),a.end());
	for(int &x:b) scanf("%i",&x),printf("%i ",upper_bound(a.begin(),a.end(),x)-a.begin());
	return 0;
}