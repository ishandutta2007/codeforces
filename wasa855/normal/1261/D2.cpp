#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
int h[N],fac[N],inv[N];
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
int C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read(),k=read();
	for(int i=1;i<=n;i++) h[i]=read();
	h[n+1]=h[1];
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++) inv[i]=inv[i]*inv[i-1]%mod;
	int m=0;
	for(int i=1;i<=n;i++) if(h[i]!=h[i+1]) m++;
	int ans=0;
	for(int i=0;i<=m/2;i++)
	{
		int ad=C(m,i)*C(m-i,i)%mod*qpow(k-2,m-i*2)%mod*qpow(k,n-m)%mod;
		ans=add(ans,ad);
	}
	ans=(qpow(k,n)-ans+mod)*inv[2]%mod;
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}