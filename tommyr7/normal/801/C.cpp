#include <bits/stdc++.h>
#define eps 1e-5
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return (long long)x*f;
}
double lx,rx,mid,ans;
int n,p;
int a[100007],b[100007];
bool check(double now)
{
	double del=0.0;
	for (int i=1;i<=n;i++) del=del+max(a[i]*now-b[i],0.0);
	if (del<now*p) return true; else return false;
}
int main()
{
	n=read(),p=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	lx=0.0,rx=10000000000.0;
	while (rx-lx>eps)
	{
		mid=double(lx+rx)/2;
		if (check(mid)) lx=mid; else rx=mid;
	}
	if (check(rx)) ans=rx; else ans=lx;
	if (ans>=10000000000.0) cout << -1 << endl; else printf("%.4lf\n",ans);
	return 0;
}