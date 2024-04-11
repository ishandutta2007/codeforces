#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,s;
int a[Maxn];
long long p[Maxn];
long long tryit(int k)
{
	for (int i=1;i<=n;i++) p[i]=a[i]+1LL*k*i;
	sort(p+1,p+n+1);
	long long res=0;
	for (int i=1;i<=k;i++) res+=p[i];
	return res;
}
int main()
{
	n=read(),s=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int lx=0,rx=n;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (tryit(mid)<=s) lx=mid; else rx=mid;
	}
	if (tryit(rx)<=s) cout << rx << ' ' << tryit(rx) << endl;
	else cout << lx << ' ' << tryit(lx) << endl;
	return 0;
}