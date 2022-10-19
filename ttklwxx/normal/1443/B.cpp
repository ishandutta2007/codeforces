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
char s[200001];
int main()
{
	int t,a,b,n,l0,ans=0,qz;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		l0=0;
		ans=0;
		qz=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1'&&(i==n||s[i+1]=='0'))
			{
				if(qz==0)ans=ans+a,qz=1;
				else ans=ans+min(a,b*l0);
			}
			if(s[i]=='0')
			{
				if(s[i-1]=='1')l0=1;
				else l0++;
			} 
		}
		printf("%d\n",ans); 
	}
	return 0;
}