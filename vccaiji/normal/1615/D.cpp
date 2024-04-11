#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[210000];
int y[210000];
int v[210000];
int par(int v)
{
	int num=0;
	for(int i=0;i<30;i++)
	 if(v&(1<<i)) num++;
	return num%2; 
}
int ffa[210000];
int val[210000];
int find(int i)
{
	if(ffa[i]==i) return i;
	int root=find(ffa[i]);
	val[i]^=val[ffa[i]];
	ffa[i]=root;
	return root;
}
bool merge(int xx,int yy,int vv)
{
	int r1=find(xx);
	int r2=find(yy);
	if(r1==r2)
	{
		if((val[xx]^val[yy])!=vv)
		 return false;
	}
	else
	{
		ffa[r1]=r2;
		val[r1]=vv^val[xx]^val[yy];
	}
	return true;
}
bool vis[210000];
int ans[210000];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&x[i],&y[i],&v[i]);
	for(int i=1;i<=n;i++)
	{
		ffa[i]=i;
		val[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		if(v[i]>=0)
		{
			merge(x[i],y[i],par(v[i]));
		}
	}
	bool oo=false;
	for(int i=1;i<=m;i++)
	{
		int a,b,p;
		scanf("%d%d%d",&a,&b,&p);
		if(oo) continue;
		if(!merge(a,b,p))
		{
			printf("NO");
			oo=true;
		}
	}
	if(oo) return;
	for(int i=1;i<=n;i++) vis[i]=false;
	printf("YES\n");
	find(1);
	vis[ffa[1]]=true;
	ans[ffa[1]]=val[1];
	for(int i=1;i<=n;i++)
	{
		int root=find(i);
		if(!vis[root])
		{
			vis[root]=true;
			ans[root]=0;
		}
		ans[i]=ans[root]^val[i];
	}
	for(int i=1;i<n;i++)
	{
		printf("%d %d ",x[i],y[i]);
		if(v[i]>=0) printf("%d",v[i]);
		else printf("%d",ans[x[i]]^ans[y[i]]);
		if(i<n-1) printf("\n");
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    	solve();
    	if(i<t) printf("\n");
	}
	return 0;
}