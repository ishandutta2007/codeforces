#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define SZ 666666
char s_[SZ],t_[SZ],*s=s_+1,*t=t_+1;
int n,m;
const int MOD=998244353;
ll w[2][SZ],rev[SZ];
inline ll qp(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return ans;
}
int K;
inline void fftinit(int n)
{
    for(K=1;K<n;K<<=1);
    w[0][0]=w[0][K]=1;
    ll g=qp(3,(MOD-1)/K);
    for(int i=1;i<K;i++) w[0][i]=w[0][i-1]*g%MOD;
    for(int i=0;i<=K;i++) w[1][i]=w[0][K-i];
}
inline void fft(int* x,int v)
{
    for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
    for(int i=0,j=0;i<K;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=K>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=K;i<<=1)
        for(int l=0;l<i>>1;l++)
        {
            register int W=w[v][K/i*l],*p=x+l+(i>>1),*q=x+l,t;
            for(register int j=0;j<K;j+=i)
            {
                p[j]=(q[j]-(t=(ll)p[j]*W%MOD)<0)?(q[j]-t+MOD):(q[j]-t);
                q[j]=(q[j]+t-MOD>=0)?(q[j]+t-MOD):(q[j]+t);
            }
        }
    if(!v) return;
    ll rv=qp(K,MOD-2);
    for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
int x[SZ],xxx[SZ],xx[SZ],yy[SZ],y[SZ],o[SZ],p[SZ];
int dt[SZ],dn,st[SZ],sn;
bool ok[SZ];
pii dp[SZ],qz[SZ];
pii f[100055][105];
char op[SZ];
bool pl[SZ];
int main()
{
//	FO(match)
	scanf("%s%s",s,t);
	n=strlen(s);m=strlen(t);fftinit(n+m);
	for(int i=0;i<n;++i)
		x[i]=(s[i]=='?')?0:s[i];
	for(int i=0;i<m;++i)
		y[m-i]=t[i],
		o[m-i]=1;
	for(int i=0;i<K;++i)
		xx[i]=x[i]*(ll)x[i]%MOD,
		yy[i]=y[i]*(ll)y[i]%MOD,
		xxx[i]=xx[i]*(ll)x[i]%MOD;
	//too lazy to optimize
	fft(xxx,0);fft(xx,0);fft(x,0);
	fft(o,0);fft(y,0);fft(yy,0);
	for(int i=0;i<K;++i)
		o[i]=(xxx[i]*(ll)o[i]-2LL*xx[i]*y[i]+(ll)x[i]*yy[i])%MOD;
	fft(o,1);
	p[0]=0;
	for(int i=1,j=0;i<m;++i)
	{
		while(j&&t[j]!=t[i]) j=p[j-1];
		if(t[j]==t[i]) ++j; p[i]=j;
	}
//	cout<<"+?\n";
	for(int g=p[m-1]-1;g!=-1;g=p[g]-1)
//		cout<<g<<"!!\n",
		dt[++dn]=m-g-1;
//	for(int i=1;i<=dn;++i)
//		cout<<dt[i]<<",";
//	cout<<"\n";
	for(int i=1;i<=dn;++i)
	{
		if(i>=3&&dt[i]-dt[i-1]==dt[i-1]-dt[i-2])
			continue;
		st[++sn]=dt[i];
	}
	assert(sn<100);
//	cout<<sn<<"??\n";
//	for(int i=1;i<=sn;++i)
//		cout<<st[i]<<",";
//	cout<<"\n";
	for(int i=m;i<=n;++i)
		if(o[i]%MOD==0) ok[i]=1;
	pii ans(0,0);
	for(int i=1;i<=n;++i)
	{
		pii cp(0,0);
		if(ok[i])
		{
		dp[i]=qz[i-m];
		for(int j=1;j<=sn;++j) if(i>st[j])
			dp[i]=max(dp[i],f[i-st[j]][j]);
		++dp[i].fi;
		cp=pii(dp[i].fi,i);
		}
		ans=max(ans,cp);
		qz[i]=max(qz[i-1],cp);
		for(int j=1;j<=sn;++j)
		{
			pii&tg=f[i][j];tg=cp;
			if(i>st[j]) tg=max(tg,f[i-st[j]][j]);
		}
	}
	cout<<ans.fi<<"\n";
//	int u=ans.se;
//	while(u) pl[u]=1,u=dp[u].se;
//	int lp=n;
//	for(int i=n;i>=1;--i)
//	{
//		if(pl[i]) lp=i;
//		char c=s[i-1];
//		if(c=='?')
//		{
//			int w=m-(lp-i);
//			if(w>=1) c=t[w-1];
//			else c='a';
//		}
//		op[i]=c;
//	}
//	puts(op+1);
}