#include<iostream>
#include<cstdio>
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
char s[1000005];
char s1[1000005];
int len;
signed main()
{
	int n;
	n=read();
	scanf("%s",s+1);
	int maxn=0,mpos=0,now;
	len=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			len=n-i+1;
			for(int j=i;j<=n;j++)s1[j-i+1]=s[j];
			break;
		}
	}
	if(len==0)
	{
		printf("0");
		return 0;
	}
	for(int i=-n;i<=n;i++)
	{
		if(i+len-1<=0||i+len-1>n)continue;
		now=0;
		for(int j=1;j<=min(len,60LL);j++)
		{
			int tw=0;
			if(s1[j]=='1')tw=1;
			if(i+j-1>=1&&i+j-1<=n&&s[i+j-1]=='1')tw=1;
			now=now*2LL+tw;
		}
		//printf("%d %d\n",i,now);
		if(now>maxn)
		{
			maxn=now;
			mpos=i;
		}
	}
	//printf("%lld %lld\n",maxn,mpos);
	for(int i=1;i<=len;i++)
	{
		if(s1[i]=='1')
		{
			printf("1");
			continue;
		}
		if(mpos+i-1>=1&&mpos+i-1<=n&&s[mpos+i-1]=='1')
		{
			printf("1");
			continue;
		}
		printf("0");
	}
	printf("\n");
	return 0;
}