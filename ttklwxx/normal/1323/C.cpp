#include<iostream>
#include<cstdio>
#include<set>
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
char str[1000005];
set<int>se;
int sl[1000005];
signed main()
{
	int n,x=0,ans=0;
	n=read();
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='(')x++;
		else x--;
		sl[i]=x;
	}
	if(x!=0)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(sl[i]==0)se.insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(sl[i]<0)
		{
			ans+=*se.lower_bound(i)-i+1;
			i=*se.lower_bound(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}