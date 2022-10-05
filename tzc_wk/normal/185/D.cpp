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
const int MAXV=1e6;
bitset<MAXV+5> vis;
int pr[MAXV/10+5],prcnt=0,phi[MAXV+5];
void sieve(int n){
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){pr[++prcnt]=i;phi[i]=i-1;}
		for(int j=1;pr[j]*i<=n&&j<=prcnt;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j];break;}
			else phi[i*pr[j]]=phi[i]*phi[pr[j]];
		}
	}
}
int qpow(int x,ll e,int mod){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%mod) if(e&1) ret=1ll*ret*x%mod;
	return ret;
}
int calc(int k,ll l,ll r,int p){
	if(k%p==0) return 1;
	int down=(qpow(k,qpow(2,l,p-1),p)-1+p)%p;
	if(!down) return qpow(2,r-l+1,p);
	int up=(qpow(k,qpow(2,r+1,p-1),p)-1+p)%p;
	return 1ll*up*qpow(down,p-2,p)%p;
}
int main(){
	sieve(MAXV);int qu;scanf("%d",&qu);
	while(qu--){
		int k,p;ll l,r;scanf("%d%lld%lld%d",&k,&l,&r,&p);
		if(k==1) printf("%d\n",2%p);
		else{
			int ans=calc(k,l,r,p);
			if(k&1) ans=1ll*ans*qpow(qpow(2,r-l,p),p-2,p)%p;
			printf("%d\n",ans);
		}
	}
	return 0;
}