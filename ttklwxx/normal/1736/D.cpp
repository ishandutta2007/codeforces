#include<iostream>
#include<cstdio>
#define int long long
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[200005];
int ans[200005],cnt;
signed main()
{
	int t,n,sl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		sl=0;
		for(int i=1;i<=2*n;i++)if(s[i]=='1')sl++;
		if(sl%2==1)
		{
			printf("-1\n");
			continue;
		}
		cnt=0;
		int now=1;
		while(now<=2*n)
		{
			//printf("%c %c\n",s[now],s[now+1]);
			if(s[now]==s[now+1])
			{
				now+=2;
				continue;
			}
			int sth=now+1;
			//printf("???%d\n",now);
			while(s[sth]!=s[now])sth++;
			if(s[now]=='1')
			{
				ans[++cnt]=now+1;
				ans[++cnt]=sth;
				swap(s[sth],s[now+1]);
			}
			else
			{
				sth=now+2;
				while(s[sth]==s[now])sth++;
				if(cnt==0||ans[cnt]!=now)ans[++cnt]=now;
				else cnt--;
				ans[++cnt]=sth;
				swap(s[sth],s[now]);
			}
			now+=2;
		}
		printf("%d ",cnt);
		for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
		printf("\n"); 
		for(int i=1;i<=n;i++)printf("%d ",2*i-1);
		printf("\n");
	}
	return 0;
}