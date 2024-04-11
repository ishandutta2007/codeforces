#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
int f[N],g[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) f[i]=f[i-1]+1;
		else f[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]<a[i+1]) g[i]=g[i+1]+1;
		else g[i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>ans) ans=f[i];
		if(a[i+1]>a[i-1])
		{
			if(f[i-1]+g[i+1]>ans) ans=f[i-1]+g[i+1];
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}