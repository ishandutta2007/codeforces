#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int t,n,m,a[N],s[N];
set<int>k;
void dfs(int l,int r)
{
	if(l>r)
		return;
	k.insert(s[r]-s[l-1]);
	if(a[l]==a[r])
		return;
	int mid=a[l]+a[r]>>1;
	int p=upper_bound(a+l,a+r+1,mid)-a;
	dfs(l,p-1);
	dfs(p,r);
}
void sol()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	k.clear();
	dfs(1,n);
	while(m--)
	{
		int x;
		cin>>x;
		if(k.count(x))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
		sol();
	return 0;
}