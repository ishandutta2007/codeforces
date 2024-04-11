#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N];
int t,n,x,b[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d\n",&n,&x);
		scanf("%s",s+1);
		int ans=0;
		for(int i=1;i<=n;i++)
			b[i]=b[i-1]-2*(s[i]-'0')+1;
		if(x==0)
			ans++;
		if(b[n]==0)
		{
			int flag=0;
			for(int i=1;i<=n;i++)
				if(b[i]==x)
					flag=1;
			if(flag)
				puts("-1");
			else
				puts("0");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]>=x)
			{
				if(b[n]<0&&(b[i]-x)%(-b[n])==0)
					ans++;
			}
			if(b[i]<=x)
			{
				if(b[n]>0&&(x-b[i])%b[n]==0)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}