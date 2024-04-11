#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,p[500005],num[500005],top;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		top=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			if(i==1||p[i]!=p[i-1])num[++top]=0;
			num[top]++;
		}
		int g=num[1],s=0,b=0;
		int now=2;
		while(now<=top&&s<=g)s+=num[now],now++;
		while(now<=top&&b<=g)b+=num[now],now++;
		if(s+b+g>n/2)printf("0 0 0\n");
		else
		{
			while(now<=top&&s+b+g+num[now]<=n/2)b+=num[now],now++;
			printf("%d %d %d\n",g,s,b);
		}
	}
	return 0;
}