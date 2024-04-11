#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[100005],b[100005];
bool flag[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)flag[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		bool f=1;
		int now=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1])b[i]=a[i],flag[b[i]]=1;
			else
			{
				while(flag[now])now++;
				if(now>a[i])
				{
					f=0;
					break;
				}
				b[i]=now;
				flag[now]=1;
			}
		}
		if(!f)printf("-1\n");
		else
		{
			for(int i=1;i<=n;i++)
			  printf("%d ",b[i]);
			printf("\n");
		}
	}
	return 0;
}