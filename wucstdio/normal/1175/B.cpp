#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int l;
ll n,st[100005],top,sum[100005];
char s[15];
bool flag[100005];
int main()
{
	scanf("%d",&l);
	sum[0]=1;
	for(int i=1;i<=l;i++)
	{
		scanf("%s",s+1);
		if(s[1]=='a')
		{
			if(flag[top])
			{
				printf("OVERFLOW!!!\n");
				return 0;
			}
			n+=sum[top];
			if(n>=(1ll<<32))
			{
				printf("OVERFLOW!!!\n");
				return 0;
			}
		}
		if(s[1]=='f')
		{
			int v;
			scanf("%d",&v);
			st[++top]=v;
			sum[top]=sum[top-1]*v;
			if(sum[top]>=(1ll<<32)||flag[top-1])flag[top]=1;
			else flag[top]=0;
		}
		if(s[1]=='e')top--;
	}
	printf("%I64d\n",n);
	return 0;
}