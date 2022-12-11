#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int n;
int op,p,q,lastans=0,tot=1,rt;
int fa[Maxn][23],mx[Maxn][23];
int faa[Maxn][23];
long long s[Maxn][23];
long long w[Maxn];
int main()
{
	memset(mx,-1,sizeof(mx));
	scanf("%d",&n);
	rt=n+1;
	faa[1][0]=rt;
	w[rt]=1000000000000007LL;
	for (int i=0;i<=20;i++) s[1][i]=w[rt];
	while (n--)
	{
		long long op,p,q;
		scanf("%lld%lld%lld",&op,&p,&q);
		p^=lastans,q^=lastans;
		if (op==1)
		{
			++tot;
			w[tot]=q;
			fa[tot][0]=p,mx[tot][0]=w[p];
			for (int i=1;i<=20;i++)
			{
				fa[tot][i]=fa[fa[tot][i-1]][i-1];
				mx[tot][i]=max(mx[tot][i-1],mx[fa[tot][i-1]][i-1]);
			}
			int now=tot;
			for (int i=20;i>=0;i--)
				if (mx[now][i]<w[tot]) now=fa[now][i];
			now=fa[now][0];
			if (now==0) now=rt;
			faa[tot][0]=now,s[tot][0]=w[now];
			for (int i=1;i<=20;i++)
			{
				faa[tot][i]=faa[faa[tot][i-1]][i-1];
				s[tot][i]=s[tot][i-1]+s[faa[tot][i-1]][i-1];
			}
		} else if (q<w[p])
		{
			lastans=0;
			printf("%d\n",0);
		} else
		{
			q-=w[p];
			int now=p,ans=1;
			for (int i=20;i>=0;i--)
				if (s[now][i]<=q)
				{
					q-=s[now][i];
					now=faa[now][i];
					ans+=(1<<i);
				}
			lastans=ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}