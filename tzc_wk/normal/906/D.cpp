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
const int MAXN=1e5;
int n,mod,w[MAXN+5];
int phi(int x){
	int tmp=x,ret=x;
	for(int i=2;i*i<=x;i++) if(tmp%i==0){
		ret=ret/i*(i-1);
		while(tmp%i==0) tmp/=i;
	} if(tmp>1) ret=ret/tmp*(tmp-1);
	return ret;
}
vector<int> seq;
int getmod(ll x,int y){return (x<y)?x:(x%y+y);}
int qpow(int x,int e,int mod){
	int ret=1;
	for(;e;e>>=1,x=getmod(1ll*x*x,mod)) if(e&1) ret=getmod(1ll*ret*x,mod);
	return ret;
}
int calc(int l,int r,int pos){
	if(seq[pos]==1) return 1;
	if(l==r) return getmod(w[l],seq[pos]);
	return qpow(w[l],calc(l+1,r,pos+1),seq[pos]);
}
int main(){
	scanf("%d%d",&n,&mod);int tmp=mod;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	seq.pb(tmp);for(;tmp!=1;tmp=phi(tmp)) seq.pb(phi(tmp));
	int qu;scanf("%d",&qu);while(qu--){
		int l,r;scanf("%d%d",&l,&r);printf("%d\n",calc(l,r,0)%mod);
	}
	return 0;
}