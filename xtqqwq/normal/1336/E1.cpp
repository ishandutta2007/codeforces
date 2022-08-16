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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m,k,cnt;
ll a[200005],b[40],c[40],d[40][270000],f[40][270000],ans[40];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void add(ll x){
	for(int i=m-1;i>=0;i--){
		if(x&(1ll<<i)){
			if(!b[i]){
				b[i]=x,cnt++;
				return;
			}
			else x^=b[i];
		}
	}
}

ll find(ll x){
	for(int i=m-1;i>=0;i--)
		if(x&(1ll<<i))
			x^=b[i];
	return x;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) add(a[i]);
	for(int i=m-1;i>=0;i--) b[i]=find(b[i]^(1ll<<i))^(1ll<<i);
	if(cnt>=(m+1)/2){
		for(int i=0;i<m;i++) if(!b[i]) c[++k]=i;
		int npl=0;
		d[0][0]=1;
		for(int i=0;i<m;i++){
			if(!b[i]) continue;
			npl++;
			ll ts=0;
			for(int j=1;j<=k;j++) if(b[i]&(1ll<<c[j])) ts+=1ll<<(j-1);
			for(int j=0;j<=npl;j++){
				for(int l=0;l<(1<<k);l++){
					f[j][l]=d[j][l];
					if(j) f[j][l]=mod(f[j][l]+d[j-1][l^ts]);
				}
			}
			for(int j=0;j<=npl;j++) swap(d[j],f[j]);
		}
		for(int i=0;i<=m;i++) for(int j=0;j<(1<<k);j++) ans[i+__builtin_popcountll(j)]+=d[i][j];
		for(int i=0;i<=m;i++) printf("%lld ",ans[i]%cys*qpow(2,n-cnt)%cys);
		printf("\n");
	}
	else{
		for(int i=0;i<m;i++) if(b[i]) c[++k]=i;
		for(int i=0;i<(1<<k);i++){
			ll now=0;
			for(int j=0;j<k;j++) if((i>>j)&1) now^=b[c[j+1]];
			ans[__builtin_popcountll(now)]++;
		}
		for(int i=0;i<=m;i++) printf("%lld ",ans[i]%cys*qpow(2,n-cnt)%cys);
		printf("\n");
	}
	return 0;
}