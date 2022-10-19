#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,rm,a[N],p[N];
struct nd
{
	int l,r;
	bool operator<(const nd k)const
	{
		return (l==k.l?r>k.r:l<k.l);
	}
}s[N],rs[N];
set<int>h;
long long dp[N][2];
void sol()
{
	scanf("%d%d",&n,&rm);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=rm;i++)
		scanf("%d%d",&rs[i].l,&rs[i].r);
	sort(rs+1,rs+rm+1);
	m=0;
	for(int i=1;i<=rm;i++)
	{
		while(m&&s[m].r>=rs[i].r)
			m--;
		m++;
		s[m]=rs[i];
	}
	h.clear();
	for(int i=1;i<=n;i++)
		h.insert(a[i]);
	h.insert(INT_MAX);
	rm=m,m=0;
	for(int i=1;i<=rm;i++)
		if(*h.lower_bound(s[i].l)>s[i].r)
			s[++m]=s[i];
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1];
		if(i==1)
			p[i]=1;
		while(p[i]<=m&&s[p[i]].l<a[i])
			p[i]++;
	}
	for(int i=0;i<=n+1;i++)
		dp[i][0]=dp[i][1]=1e18;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				long long c=1e18;
				if(i==1)
				{
					if(p[1]>1)
					{
						if(j==0)
							c=a[1]-s[1].r;
						else
							c=2ll*(a[1]-s[1].r);
					}
					else
						c=0;
				}
				else
				{
					if(p[i-1]==p[i])
						c=0;
					else
					{
						for(int x=p[i-1]-1;x<p[i];x++)
						{
							long long t=0;
							if(x>=p[i-1])
							{
								if(k==0)
									t+=2ll*(s[x].l-a[i-1]);
								else
									t+=s[x].l-a[i-1];
							}
							if(x+1<p[i])
							{
								if(j==0)
									t+=a[i]-s[x+1].r;
								else
									t+=2ll*(a[i]-s[x+1].r);
							}
							c=min(c,t);
						}
					}
				}
				if(i==n)
				{
					if(p[i]<=m)
					{
						if(j==0)
							c+=2ll*(s[m].l-a[i]);
						else
							c+=s[m].l-a[i];
					}
				}
				dp[i][j]=min(dp[i][j],dp[i-1][k]+c);
			}
		}
	}
	printf("%lld\n",min(dp[n][0],dp[n][1]));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();

	return 0;
}