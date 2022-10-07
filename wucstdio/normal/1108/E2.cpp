#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Data
{
	int v;
	int lorr;
	int p;
}a[200005];
int n,m,c[200005],tmp[200005],l[200005],r[200005],ans,res[200005],top;
int rnk[200005],maxx[200005];
bool cmp(Data a,Data b)
{
	return a.v<b.v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&tmp[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		a[++top].v=l[i]-1;
		a[top].p=i;
		a[top].lorr=0;
		a[++top].v=r[i];
		a[top].p=i;
		a[top].lorr=1;
	}
	a[++top].v=n;
	sort(a+1,a+top+1,cmp);
	int now=0;
	for(int i=1;i<=top;i++)
	{
		if(a[i].v!=a[i-1].v)now++;
		rnk[now]=a[i].v;
		if(a[i].lorr==0)l[a[i].p]=now+1;
		else r[a[i].p]=now;
	}
	int nown=1;
	for(int i=1;i<=now;i++)
	{
		c[i]=2147483647;
		maxx[i]=-2147483647;
		while(nown<=rnk[i])
		{
			c[i]=min(c[i],tmp[nown]);
			maxx[i]=max(maxx[i],tmp[nown]);
			nown++;
		}
	}
	n=now;
	for(int i=1;i<=n;i++)tmp[i]=c[i];
	for(int i=n;i>=1;i--)tmp[i]-=tmp[i-1];
	int ans=0;
	res[0]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)c[j]=tmp[j];
		for(int j=1;j<=m;j++)
		  if(r[j]<i||l[j]>i)
		    c[l[j]]--,c[r[j]+1]++;
		int minn=2147483647;
		for(int j=1;j<=n;j++)
		{
			c[j]+=c[j-1];
			minn=min(minn,c[j]);
		}
		res[i]=maxx[i]-minn;
		if(res[ans]<res[i])ans=i;
	}
	printf("%d\n",res[ans]);
	int num=0;
	for(int i=1;i<=m;i++)
	  if(r[i]<ans||l[i]>ans)
	    res[++num]=i;
	printf("%d\n",num);
	for(int i=1;i<=num;i++)
	  printf("%d ",res[i]);
	printf("\n");
	return 0;
}