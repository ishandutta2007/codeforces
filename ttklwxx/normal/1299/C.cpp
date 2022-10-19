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
int a[2000001],cnt,het[2000001],sl[2000001];
signed main()
{
	int n;
	n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
    	het[++cnt]=a[i];
    	sl[cnt]=1;
    	while(cnt>1&&het[cnt]*sl[cnt-1]<het[cnt-1]*sl[cnt])cnt--,sl[cnt]+=sl[cnt+1],het[cnt]+=het[cnt+1];
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=sl[i];j++)printf("%.9lf\n",1.0*het[i]/sl[i]);
	} 
}