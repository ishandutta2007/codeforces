#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int a[N],n,p;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1e9;
	for(int i=1;i<=n;i++)
		l=max(l,a[i]-(i-1));
	for(int i=1;i<=n&&i+p-1<=n;i++)
		r=min(r,a[i+p-1]-(i-1)-1);
	if(l<=r)
	{
		cout<<r-l+1<<endl;
		for(int i=l;i<=r;i++)
			cout<<i<<' ';
	}
	else
		cout<<0<<endl;
	return 0;
}