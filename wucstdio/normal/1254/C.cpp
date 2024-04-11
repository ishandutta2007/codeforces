#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,sa[100005],type[100005];
ll s[100005];
bool cmp(int a,int b)
{
	return s[a]>s[b];
}
int main()
{
	scanf("%d",&n);
	int now=2;
	for(int i=3;i<=n;i++)
	{
		printf("2 %d %d %d\n",1,now,i);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x==1)now=i;
	}
	sa[1]=1;
	for(int i=2;i<=n;i++)
	{
		sa[i]=i;
		if(i==now)continue;
		printf("1 %d %d %d\n",1,now,i);
		fflush(stdout);
		scanf("%lld",&s[i]);
	}
	sort(sa+1,sa+n+1,cmp);
	int top=sa[1];
	for(int i=2;i<=n;i++)
	{
		if(i==top)continue;
		printf("2 %d %d %d\n",1,top,i);
		fflush(stdout);
		scanf("%d",&type[i]);
	}
	printf("0 1 ");
	for(int i=n;i>=1;i--)
	{
		if(type[sa[i]]==-1)
		  printf("%d ",sa[i]);
	}
	printf("%d ",top);
	for(int i=1;i<=n;i++)
	  if(type[sa[i]]==1)
	    printf("%d ",sa[i]);
	printf("\n");
	return 0;
}