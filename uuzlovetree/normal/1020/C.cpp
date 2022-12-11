#include<bits/stdc++.h>
#define ll long long
#define maxn 3005
using namespace std;
int n,m;
int p[maxn],c[maxn];
vector<int> val[maxn];
int num[maxn];
int a[maxn],cnt;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&p[i],&c[i]);
		val[p[i]].push_back(c[i]);
	}
	for(int i=1;i<=m;++i)sort(val[i].begin(),val[i].end());
	ll ans=1e15;
	for(int i=n;i>=0;--i)
	{
		ll res=0,tot=val[1].size();
		cnt=0;
		for(int j=2;j<=m;++j)if(val[j].size()>i)
		{
			for(int k=0;k<val[j].size()-i;++k)
			{
				res+=val[j][k];++tot;
			}
		}
		for(int j=2;j<=m;++j)
		{
			int mind=val[j].size()-i;
			for(int k=max(mind,0);k<val[j].size();++k)
			{
				a[++cnt]=val[j][k];
			}
		}
		sort(a+1,a+cnt+1);
		for(int j=1;j<=cnt;++j)
		{
			if(tot>i)break;
			tot++;res+=a[j];
		}
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}