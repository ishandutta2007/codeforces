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
int a,b,c,n,ans=0;
int main()
{
	a=read(),b=read(),c=read();
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x<c&&x>b) ++ans;
	}
	cout << ans << endl;
	return 0;
}