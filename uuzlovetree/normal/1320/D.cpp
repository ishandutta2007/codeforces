#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
typedef long long ll;
const ll bas0=31,bas1=37;
const ll mod0=1000000007,mod1=998244353,B=1000000009;
int n,q,cnt;
int a[maxn],b[maxn];
int c[maxn],d[maxn];
ll hc[2][maxn],hd[2][maxn],xp[2][maxn];
ll getc(int l,int r)
{
	ll x=hc[0][r]-hc[0][l-1]*xp[0][r-l+1]%mod0;
	x=(x%mod0+mod0)%mod0;
	ll y=hc[1][r]-hc[1][l-1]*xp[1][r-l+1]%mod1;
	y=(y%mod1+mod1)%mod1;
	return x*B+y;
}
ll getd(int l,int r)
{
	ll x=hd[0][r]-hd[0][l-1]*xp[0][r-l+1]%mod0;
	x=(x%mod0+mod0)%mod0;
	ll y=hd[1][r]-hd[1][l-1]*xp[1][r-l+1]%mod1;
	y=(y%mod1+mod1)%mod1;
	return x*B+y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%1d",&a[i]);
	for(int i=1;i<=n;++i)if(!a[i])b[++cnt]=i;
	for(int i=1;i<=cnt;++i)
	{
		c[i]=b[i]&1;
		d[i]=c[i]^1;
	}
	xp[0][0]=xp[1][0]=1;
	for(int i=1;i<=cnt;++i)
	{
		xp[0][i]=xp[0][i-1]*bas0%mod0;
		xp[1][i]=xp[1][i-1]*bas1%mod1;
	}
	for(int i=1;i<=cnt;++i)
	{
		hc[0][i]=(hc[0][i-1]*bas0+c[i])%mod0;
		hc[1][i]=(hc[1][i-1]*bas1+c[i])%mod1;
		hd[0][i]=(hd[0][i-1]*bas0+d[i])%mod0;
		hd[1][i]=(hd[1][i-1]*bas1+d[i])%mod1;
	}
	scanf("%d",&q);
	while(q--)
	{
		int l1,l2,len;
		bool yes=1;
		scanf("%d%d%d",&l1,&l2,&len);
		int r1=l1+len-1,r2=l2+len-1;
		int L1=lower_bound(b+1,b+cnt+1,l1)-b,R1=upper_bound(b+1,b+cnt+1,r1)-b-1;
		int L2=lower_bound(b+1,b+cnt+1,l2)-b,R2=upper_bound(b+1,b+cnt+1,r2)-b-1;
		if(R1-L1!=R2-L2)yes=0;
		else
		{
			if(L1<=R1)
			{
				if((l1&1)!=(l2&1))
				{
					if(getc(L1,R1)!=getd(L2,R2))yes=0;
				}
				else
				{
					if(getc(L1,R1)!=getc(L2,R2))yes=0;
				}
			}
		}
		if(yes)printf("Yes\n");
		else printf("No\n");
	}
}