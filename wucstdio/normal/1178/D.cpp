#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool flag[100005];
int n,prime[100005],num;
void pre(int n)
{
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])prime[++num]=i;
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	scanf("%d",&n);
	pre(2*n);
	for(int m=n;m<=n+n/2;m++)
	{
		if(!flag[m])
		{
			printf("%d\n",m);
			for(int i=1;i<=n;i++)printf("%d %d\n",i,i%n+1);
			for(int i=1;i+n<=m;i++)printf("%d %d\n",i,i+n/2);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}