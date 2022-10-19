#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
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
char s[2000005];
bool bj[2000005];
bool vis[27];
signed main()
{
	int t,n,k,ans,pre;
	bool flag;
	char ch;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		k=read();
		for(int i=1;i<=26;i++)vis[i]=false;
		for(int i=1;i<=k;i++)
		{
			ch=getchar();
			while(ch<'a'||ch>'z')ch=getchar();
			vis[ch-'a'+1]=true;
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[s[i]-'a'+1]==true)bj[i]=true;
			else bj[i]=false;
		}
		pre=1;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(bj[i]==true)
			{
				ans=max(ans,i-pre);
				pre=i;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}