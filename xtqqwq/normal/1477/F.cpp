#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=2000,cys=998244353;
int n,k,L;
ll a[55],fac[2005],inv[2005],d[2005][2005],tmp[2005][2005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),L+=a[i];
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%cys;
	inv[N]=qpow(fac[N],cys-2);
	for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	d[0][0]=1;
	ll invL=qpow(L,cys-2);
	for(int i=1;i<=n;i++){
		vector<pair<pii,ll> > vec(0);
		for(int j=0;j*k<a[i];j++){
			ll tmp=inv[j]*qpow((a[i]-j*k)*invL%cys,j)%cys;
			if(j&1) tmp=mod(cys-tmp);
			vec.pb(mp(mp(j,a[i]-j*k),tmp));
			if(j>0){
				tmp=inv[j-1]*qpow((a[i]-j*k)*invL%cys,j-1)%cys;
				if(j&1) tmp=mod(cys-tmp);
				vec.pb(mp(mp(j-1,a[i]-j*k),tmp));
			}
		}
		for(int j=0;j<=N;j++) for(int k=0;k<=N;k++) tmp[j][k]=d[j][k],d[j][k]=0;
		for(int j=0;j<=N;j++)
			for(int k=0;k<=N;k++)
				if(tmp[j][k])
					for(auto r:vec)
						if(j+r.fi.fi<=N&&k+r.fi.se<=N)
							d[j+r.fi.fi][k+r.fi.se]=(d[j+r.fi.fi][k+r.fi.se]+tmp[j][k]*r.se)%cys;
	}
	for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) d[i][j]=mod(cys-d[i][j]);
	d[0][L]=mod(d[0][L]+1);
	ll ans=0;
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			if(d[i][j])
				ans=(ans+d[i][j]*fac[i]%cys*qpow(cys+1-j*invL%cys,cys-2-i)%cys)%cys;
	printf("%lld\n",ans);
	return 0;
}