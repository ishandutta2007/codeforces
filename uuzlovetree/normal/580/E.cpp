#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
const int bas1=31,bas2=37;
const int mod1=998244353,mod2=1000000009;
int n,m,q;
int xp1[maxn],xp2[maxn];
int a[maxn];
int hs1[maxn<<2],hs2[maxn<<2],sumxp1[maxn<<2],sumxp2[maxn<<2],setv[maxn<<2];
void pushup(int rt)
{
	hs1[rt]=(hs1[rt<<1]+hs1[rt<<1|1])%mod1;
	hs2[rt]=(hs2[rt<<1]+hs2[rt<<1|1])%mod2;
	sumxp1[rt]=(sumxp1[rt<<1]+sumxp1[rt<<1|1])%mod1;
	sumxp2[rt]=(sumxp2[rt<<1]+sumxp2[rt<<1|1])%mod2;
}
void update(int rt,int d)
{
	hs1[rt]=1ll*sumxp1[rt]*d%mod1;
	hs2[rt]=1ll*sumxp2[rt]*d%mod2;
	setv[rt]=d; 
}
void pushdown(int rt)
{
	if(setv[rt])
	{
		update(rt<<1,setv[rt]);
		update(rt<<1|1,setv[rt]);
		setv[rt]=0;
	}
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		hs1[rt]=1ll*a[l]*xp1[n-l]%mod1;
		hs2[rt]=1ll*a[l]*xp2[n-l]%mod2;
		sumxp1[rt]=xp1[n-l];
		sumxp2[rt]=xp2[n-l];
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void cover(int rt,int l,int r,int ql,int qr,int d)
{
	if(ql<=l&&r<=qr)
	{
		setv[rt]=d;
		hs1[rt]=1ll*sumxp1[rt]*d%mod1;
		hs2[rt]=1ll*sumxp2[rt]*d%mod2;
		return; 
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(ql<=mid)cover(rt<<1,l,mid,ql,qr,d);
	if(qr>mid)cover(rt<<1|1,mid+1,r,ql,qr,d);
	pushup(rt);
}
pair<int,int> query(int rt,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return make_pair(hs1[rt],hs2[rt]);
	pushdown(rt);
	int mid=(l+r)>>1;
	pair<int,int> ans=make_pair(0,0);
	if(ql<=mid)
	{
		pair<int,int> now=query(rt<<1,l,mid,ql,qr);
		ans.first=(ans.first+now.first)%mod1;
		ans.second=(ans.second+now.second)%mod2;
	}
	if(qr>mid)
	{
		pair<int,int> now=query(rt<<1|1,mid+1,r,ql,qr);
		ans.first=(ans.first+now.first)%mod1;
		ans.second=(ans.second+now.second)%mod2;
	}
	pushup(rt);
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%1d",&a[i]),a[i]++;
	xp1[0]=xp2[0]=1;
	for(int i=1;i<=n;++i)
	{
		xp1[i]=1ll*xp1[i-1]*bas1%mod1;
		xp2[i]=1ll*xp2[i-1]*bas2%mod2;
	}
	q+=m;
	build(1,1,n);
	while(q--)
	{
		int op,l,r,d;
		scanf("%d%d%d%d",&op,&l,&r,&d);
		if(op==1)
		{
			++d;
			cover(1,1,n,l,r,d);
		}
		else
		{
			int border=r-l+1-d;
			if(!border)
			{
				puts("YES");
				continue;
			}
			pair<int,int> ans1=query(1,1,n,l,l+border-1);
			pair<int,int> ans2=query(1,1,n,r-border+1,r);
			ans2.first=1ll*ans2.first*xp1[r-(l+border-1)]%mod1;
			ans2.second=1ll*ans2.second*xp2[r-(l+border-1)]%mod2;
			if(ans1==ans2)puts("YES");
			else puts("NO");
		}
	}
}