#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node
{
	int data;
	int x;
}a[2005];
int n,k,ans,num[2005],xxx;
bool flag[2005];
bool cmp(Node a,Node b)
{
	return a.data>b.data||a.data==b.data&&a.x<b.x;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].data);
		a[i].x=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=k;i++)
	{
		ans+=a[i].data;
		flag[a[i].x]=1;
	}
	printf("%d\n",ans);
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==1)
		{
			num[++xxx]=i-last;
			last=i;
		}
	}
	while(flag[n--]==0)num[k]++;
	for(int i=1;i<=k;i++)
	  printf("%d ",num[i]);
	printf("\n");
	return 0;
}