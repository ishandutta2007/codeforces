#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
const int MAXV=1e6;
const int MOD=1e9+7;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,k,q;
bitset<MAXV+5> vis;
int pr[MAXV/10+5],prcnt=0,phi[MAXV+5];
vector<int> facs[MAXV+5];
void sieve(int n){
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){pr[++prcnt]=i;phi[i]=i-1;}
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0){phi[pr[j]*i]=phi[i]*pr[j];break;}
			else phi[pr[j]*i]=phi[pr[j]]*phi[i];
		}
	}
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i)
		facs[j].pb(i);
}
int fac[MAXN+5],ifac[MAXN+5];
void init_fac(int n){
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qpow(fac[n],MOD-2);for(int i=n-1;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
}
int binom(int n,int k){
	if(n<k) return 0;
	return 1ll*fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}
int cnt[MAXV+5],ans=0;
void insert(int x){
	ffe(it,facs[x]){
		ans=(ans+1ll*binom(cnt[*it],k-1)*phi[*it])%MOD;
		cnt[*it]++;
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&q);
	sieve(MAXV);init_fac(MAXN);
	for(int i=1;i<=n+q;i++){
		int x;scanf("%d",&x);insert(x);
		if(i>n) printf("%d\n",ans);
	}
	return 0;
}