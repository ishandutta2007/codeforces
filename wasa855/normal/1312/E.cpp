#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 505
int f[N][N],a[N];
int g[N];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) f[i][i]=a[i];
	for(int k=2;k<=n;k++)
	{
		for(int i=1;i+k-1<=n;i++)
		{
			int j=i+k-1;
			for(int c=i+1;c<=j;c++)
			{
				if(f[i][c-1]==f[c][j]&&f[i][c-1]!=0)
				{
					f[i][j]=f[i][c-1]+1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		g[i]=INF;
		for(int j=1;j<=i;j++)
		{
			if(g[j-1]+1<g[i]&&f[j][i]!=0) g[i]=g[j-1]+1;
		}
	}
	cout<<g[n]<<endl;
	return 0;
}