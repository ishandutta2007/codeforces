#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
int n,k,p,sa[100005];
ll a[100005],v[100005][7],f[100005][1<<7];
priority_queue<ll,vector<ll>,greater<ll> >q;
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int calc(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x&1;
		x>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	  for(int j=0;j<p;j++)
	    scanf("%lld",&v[i][j]);
	for(int i=1;i<=n;i++)sa[i]=i;
	sort(sa+1,sa+n+1,cmp);
	for(int s=1;s<(1<<p);s++)f[0][s]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int s=0;s<(1<<p);s++)f[i][s]=-1;
		for(int s=0;s<(1<<p);s++)
		{
			if(f[i-1][s]==-1)continue;
			f[i][s]=max(f[i][s],f[i-1][s]+(i-calc(s)<=k)*a[sa[i]]);
			for(int j=0;j<p;j++)
			{
				if((1<<j)&s);
				else
				{
					f[i][s|(1<<j)]=max(f[i][s|(1<<j)],f[i-1][s]+v[sa[i]][j]);
				}
			}
		}
	}
	printf("%lld\n",f[n][(1<<p)-1]);
	return 0;
}