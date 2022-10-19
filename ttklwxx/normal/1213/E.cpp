#include<iostream>
#include<cstdio>
#include<algorithm>
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
char s[11],t[11],ans[11];
signed main()
{
	int n;
	n=read();
	scanf("%s%s",s+1,t+1);
	printf("YES\n");
	if(s[1]==s[2]||t[1]==t[2])
	{
		if(s[1]==s[2])swap(s,t);
		ans[1]=s[2];
		ans[2]=s[1];
		ans[3]='a'+'b'+'c'-s[1]-s[2];
		if(s[1]==s[2])
		{
			ans[1]='a';
			ans[2]='b';
			ans[3]='c';
		}
		for(int i=1;i<=n;i++)printf("%s",ans+1);
		return 0;
	}
	if(s[1]==t[1])
	{
		ans[3]=s[1];
		if(s[1]=='a')ans[1]='b';
		else ans[1]='a';
		ans[2]='a'+'b'+'c'-ans[1]-ans[3];
		for(int i=1;i<=n;i++)printf("%c",ans[1]);
		for(int i=1;i<=n;i++)printf("%c",ans[2]);
		for(int i=1;i<=n;i++)printf("%c",ans[3]);
		return 0;
	}
	if(s[1]==t[2])
	{
		if(s[2]==t[1])
		{
			for(int i=1;i<=n;i++)printf("%c",s[1]);
			for(int i=1;i<=n;i++)printf("%c",'a'+'b'+'c'-s[1]-t[1]);
			for(int i=1;i<=n;i++)printf("%c",t[1]);
			return 0;
		}
		ans[1]=s[2];
		ans[2]=t[2];
		ans[3]=t[1];
		for(int i=1;i<=n;i++)printf("%c",ans[1]);
		for(int i=1;i<=n;i++)printf("%c",ans[2]);
		for(int i=1;i<=n;i++)printf("%c",ans[3]);
		return 0;
	}
	ans[1]=t[2];
	ans[2]=t[1];
	ans[3]=s[1];
	for(int i=1;i<=n;i++)printf("%c",ans[1]);
	for(int i=1;i<=n;i++)printf("%c",ans[2]);
	for(int i=1;i<=n;i++)printf("%c",ans[3]);
	return 0;
}