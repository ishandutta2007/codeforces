#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k;
bool g[100007][5];
int a[100007],r[100007];
int bin[5];
int main()
{
	n=read(),k=read();
	memset(g,false,sizeof(g));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
		{
			int x=read();
			if (x==1) g[i][j]=true; else g[i][j]=false;
		}
	memset(a,0,sizeof(a));
	memset(r,0,sizeof(r));
	bin[0]=1;
	for (int i=1;i<=k;i++)
		bin[i]=2*bin[i-1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			if (g[i][j]) a[i]+=bin[j-1];
	for (int i=1;i<=n;i++)
		++r[a[i]];
	for (int i=0;i<bin[k];i++)
		for (int j=0;j<bin[k];j++)
			if (r[i]>0&&r[j]>0&&((i&j)==0))
			{
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}