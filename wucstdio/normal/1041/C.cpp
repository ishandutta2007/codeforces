#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node
{
	int data;
	int p;
}a[200005];
int n,m,d,maxl[200005],ans,day[200005];
bool cmp(Node a,Node b)
{
	return a.data<b.data;
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].data);
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i].data-a[now].data-1>=d)maxl[i]=now++;
		if(now>1)now--;
		ans=max(ans,i-maxl[i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	  day[a[i].p]=(i-1)%ans+1;
	for(int i=1;i<=n;i++)
	  printf("%d ",day[i]);
	printf("\n");
	return 0;
}