#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,i,l,r,x,fa[N],beat[N];
int gf(int x)
{
	if(fa[x]!=x)
		fa[x]=gf(fa[x]);
	return fa[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+1;i++)
		fa[i]=i;
	while(m--)
	{
		scanf("%d%d%d",&l,&r,&x);
		for(i=gf(l);i<=r;i=gf(i+1))
			if(i!=x)
				beat[i]=x,fa[i]=i+1;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",beat[i]);
	return 0;
}