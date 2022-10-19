#include<iostream>
#include<cstdio>
#include<cstring>
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
int main()
{
	int t,x,y,n,su,sd,sr,sl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		su=sd=sr=sl=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='U')su++;
			else if(s[i]=='D')sd++;
			else if(s[i]=='L')sl++;
			else sr++;
		}
		if(-sl<=x&&x<=sr&&-sd<=y&&y<=su)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}