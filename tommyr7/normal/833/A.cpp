#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int T,a,b,lx,rx,x;
bool check;
int main()
{
	T=read();
	while (T--)
	{
		a=read(),b=read();
		lx=1,rx=1000007;
		while (rx-lx>1)
		{
			int mid=(lx+rx)/2;
			if (1LL*mid*mid*mid<=1LL*a*b) lx=mid; else rx=mid;
		}
		if (1LL*lx*lx*lx==1LL*a*b) x=lx;
		else if (1LL*rx*rx*rx==1LL*a*b) x=rx;
		else x=0;
		check=false;
		if (x>0)
		{
			if (a%x==0&&b%x==0) check=true;
		}
		if (check) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}