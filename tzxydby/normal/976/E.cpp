#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
struct node
{
	int x,y,d,c;
	bool operator<(const node k)const
	{
		return c>k.c;
	}
}a[N];
int n,u,v,ans,s[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>u>>v;
	v=min(n,v);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].d=(a[i].x<<u)-a[i].y;
		a[i].c=a[i].x-a[i].y;
		a[i].d=max(a[i].d,0LL);
		a[i].c=max(a[i].c,0LL);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i].c;
	s[n+1]=s[n];
	for(int i=1;i<=n;i++)
	{
		if(i<=v)
			ans=max(ans,s[v]-a[i].c+a[i].d);
		else if(v)
			ans=max(ans,s[v-1]+a[i].d);
	}
	for(int i=1;i<=n;i++)
		ans+=a[i].y;
	cout<<ans<<endl;
	return 0;
}