#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,a[N],g,x;
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		g=__gcd(g,a[i]-a[i-1]);
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		cout<<__gcd(a[1]+x,g)<<' ';
	}
	return 0;
}