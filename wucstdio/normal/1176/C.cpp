#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[500005],p[15][500005],top[15],head[15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==4)p[1][++top[1]]=i;
		if(a[i]==8)p[2][++top[2]]=i;
		if(a[i]==15)p[3][++top[3]]=i;
		if(a[i]==16)p[4][++top[4]]=i;
		if(a[i]==23)p[5][++top[5]]=i;
		if(a[i]==42)p[6][++top[6]]=i;
	}
	for(int i=1;i<=6;i++)head[i]=1;
	int ans=0;
	for(int i=1;i<=top[1];i++)
	{
		int now=p[1][i];
		bool flag=1;
		for(int j=2;j<=6;j++)
		{
			while(head[j]<=top[j]&&p[j][head[j]]<now)head[j]++;
			if(head[j]>top[j])
			{
				flag=0;
				break;
			}
			now=p[j][head[j]++];
		}
		if(flag)ans++;
	}
	printf("%d\n",n-ans*6);
	return 0;
}