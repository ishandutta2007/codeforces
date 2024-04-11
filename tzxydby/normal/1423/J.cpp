#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	char c=getchar();long long x=0;int e=0;
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-')e=1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(long long)(c-'0');
		c=getchar();
	}
	return e?-x:x;
}
void pt(long long v){
	if(v<0)
	{
		putchar('-');
		v=-v;
	}
	if(!v)
	{
		putchar('0');
		return;
	}
	if(v>=10) pt(v/10);
	putchar('0'+(v%10));
}
const int mod=1e9+7;
int qp(long long a,int b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
__int128 n,ans;
void sol()
{
	n=rd();
	ans=(n/2+2)*(n/2+2)/4%mod;
	int x=ans;
	pt(x);
	puts("");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		sol();
	return 0;
}