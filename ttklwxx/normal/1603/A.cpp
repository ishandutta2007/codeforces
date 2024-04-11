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
int a[1000005];
bool sc[1000005];
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
signed main()
{
	int t,n,x,sl;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sl=1;
		flag=true;
		for(int i=1;i<=n;i++)
		{
			sl=sl/gcd(sl,i+1)*(i+1);
			if(a[i]%sl==0)
			{
				flag=false;
				break;
			}
			if(sl>1000000000)break; 
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}