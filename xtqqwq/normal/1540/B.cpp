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

const int cys=1000000007;
int n,tot;
int dep[205],f[205],siz[205],v[405],nxt[405],h[205];
ll d[205][205];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	for(int i=1;i<=n;i++) d[i][0]=1;
	for(int i=1;i<=n;i++) d[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=((cys+1)/2*d[i-1][j]+(cys+1)/2*d[i][j-1])%cys;
	ll invn=qpow(n,cys-2),ans=0;
	for(int i=1;i<=n;i++){
		dep[i]=0; dfs1(i,-1);
		for(int j=i+1;j<=n;j++){
			vector<int> vec(0);
			ans=(ans+invn*siz[j])%cys;
			int lst=j,x=j;
			while(f[x]!=i){
				x=f[x];
				ans=(ans+invn*(siz[x]-siz[lst])%cys*d[dep[x]][dep[j]-dep[x]])%cys;
				lst=x;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}