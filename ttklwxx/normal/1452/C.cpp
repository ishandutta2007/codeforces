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
signed main()
{
	int t,n,sl1,sl2,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		sl1=0;
		sl2=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='(')sl1++;
			else if(s[i]=='[')sl2++;
			else if(s[i]==')')
			{
				if(sl1>=1)ans++,sl1--;
			}
			else
			{
				if(sl2>=1)ans++,sl2--;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}