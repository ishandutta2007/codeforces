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
char s[400005];
int f[400005],n;
int qz[400005];
int sta[400005],ttop;
signed main()
{
	int q,opt,l,r;
	n=read();
	q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')sta[++ttop]=i;
		else if(ttop>=1)
		{
			f[i]=f[sta[ttop]-1]+1;
			ttop--;
		}
		qz[i]=qz[i-1]+f[i];
	}
	for(int i=1;i<=q;i++)
	{
		opt=read();
		l=read();
		r=read();
		printf("%lld\n",qz[r]-qz[l-1]-f[l-1]*(f[r]-f[l-1]));
	}
	return 0;
}