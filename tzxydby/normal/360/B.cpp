#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,k,a[N],x[N],y[N],o[N],b[N],dp[N];
vector<int>v;
void init()
{
	for(int i=0;i<=n;i++)
		b[i]=0;
}
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]=max(b[i],v);
}
int ask(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v=max(v,b[i]);
	return v;
}
bool cmp(int i,int j)
{
	return x[i]==x[j]?i<j:x[i]>x[j];
}
int check(int m)
{
	v.clear();
	init();
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		x[i]=a[i]-i*m;
		y[i]=a[i]+i*m;
		v.push_back(y[i]);
		o[i]=i;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sort(o+1,o+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int u=o[i];
		y[u]=lower_bound(v.begin(),v.end(),y[u])-v.begin()+1;
		dp[u]=ask(y[u])+1;
		add(y[u],dp[u]);
		mx=max(mx,dp[u]);
	}
	return mx+k>=n;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=-1,r=2e9;
	while(r-l>1)
	{
		int m=l+r>>1;
		if(check(m))
			r=m;
		else
			l=m;
	}
	cout<<r<<endl;
	return 0;
}