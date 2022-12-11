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
int n,q,a[Maxn],next[Maxn][307],f[Maxn][307];
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j=1;j<=300;j++)
			next[i][j]=i+a[i]+j;
	}
	memset(f,0,sizeof(f));
	for (int i=n;i;i--)
		for (int j=1;j<=300;j++)
			if (next[i][j]>n) f[i][j]=1; else f[i][j]=f[next[i][j]][j]+1;
	q=read();
	while (q--)
	{
		int p=read(),k=read();
		if (k<=300) cout << f[p][k] << endl; else
		{
			int ans=0;
			while (p<=n)
			{
				++ans;
				p+=k+a[p];
			}
			cout << ans << endl;
		}
	}
	return 0;
}