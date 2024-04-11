#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m1,m2,f[N],g[N];
int gf(int x){return (f[x]==x)?x:f[x]=gf(f[x]);}
int gg(int x){return (g[x]==x)?x:g[x]=gg(g[x]);}
int xx[N],yy[N],tot;
vector<int>A,B;
int main()
{
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;++i)f[i]=g[i]=i;
	while(m1--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[gf(x)]=gf(y);
	}
	while(m2--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[gg(x)]=gg(y);
	}
	for(int i=2;i<=n;++i)
	{
		int f1=gf(1),f2=gf(i);
		int g1=gg(1),g2=gg(i);
		if(f1!=f2&&g1!=g2)
		{
			xx[++tot]=1;yy[tot]=i;
			f[f1]=f2;
			g[g1]=g2;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(gf(i)==gf(1)&&gg(i)!=gg(1)&&gg(i)==i) 
			A.push_back(i);
		if(gg(i)==gg(1)&&gf(i)!=gf(1)&&gf(i)==i) 
			B.push_back(i);
	}
	int tmp=min(A.size(),B.size());
	printf("%d\n",tot+tmp);
	for(int i=1;i<=tot;i++) 
		printf("%d %d\n",xx[i],yy[i]);
	while(tmp>=1)
	{
		tmp--;
		printf("%d %d\n",A[tmp],B[tmp]);
	}
	return 0;
}