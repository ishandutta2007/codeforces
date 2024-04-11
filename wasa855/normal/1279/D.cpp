#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int inv(int x)
{
	return qpow(x,mod-2);
}
#define N 1000005
int pos[N],p[N],k[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	int posi=inv(n);
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		int mul=posi*inv(k[i])%mod;
		for(int j=1;j<=k[i];j++)
		{
			int u=read();
			p[u]++;
			pos[u]=(pos[u]+mul)%mod;
		}
	}
	for(int i=1;i<=1000000;i++)
	{
		p[i]=p[i]*posi%mod;
	}
	int ans=0;
	for(int i=1;i<=1000000;i++)
	{
		ans=(ans+p[i]*pos[i])%mod;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}