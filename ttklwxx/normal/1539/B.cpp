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
char s[200005];
int qz[200005];
signed main()
{
	int n,q,l,r;
	n=read();
	q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+s[i]-'a'+1;
	}
	for(int i=1;i<=q;i++)
	{
		l=read();
		r=read();
		printf("%d\n",qz[r]-qz[l-1]);
	}
	return 0;
}