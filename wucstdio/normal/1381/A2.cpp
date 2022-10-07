#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,ans[200005],top;
char a[100005],b[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s%s",a+1,b+1);
		top=0;
		int now=1;
		for(int i=n;i>=1;i--)
		{
			if((a[now]==b[i])^((n-i)&1))ans[++top]=1;
			ans[++top]=i;
			now=(now<=n/2?n-now+1:n-now+2);
		}
		printf("%d ",top);
		for(int i=1;i<=top;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}