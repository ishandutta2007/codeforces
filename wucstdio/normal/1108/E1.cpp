#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,c[305],tmp[305],l[305],r[305],ans,res[305];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&tmp[i]);
	for(int i=n;i>=1;i--)
	  tmp[i]-=tmp[i-1];
	for(int i=1;i<=m;i++)
	  scanf("%d%d",&l[i],&r[i]);
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
		res[i]=c[i]-minn;
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