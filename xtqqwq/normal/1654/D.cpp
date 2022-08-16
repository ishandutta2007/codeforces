// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,tot,ptot;
int v[400005],c[400005],nxt[400005],h[200005],prm[200005],now[200005],p0[200005],mina[200005];
ll ans[200005],pw[200005];
pii a[200005];
bool fl[200005],vis[200005];
vector<pii> vec[200005];
vector<int> stk;

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void getprime(int m){
	fl[1]=1;
	for(int i=2;i<=m;i++){
		if(!fl[i]) prm[++ptot]=i,p0[i]=i;
		for(int j=1;j<=ptot&&i*prm[j]<=m;j++){
			fl[i*prm[j]]=1,p0[i*prm[j]]=prm[j];
			if(i%prm[j]==0) break;
		}
	}
}

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=-z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
//	cout<<"dfs "<<u<<' '<<ans[u]<<' ';
//	for(int i=1;i<=n;i++) cout<<now[i]<<' ';
//	cout<<endl;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(c[p]>0){
			ans[v[p]]=ans[u];
			for(auto r:vec[c[p]]){
				now[r.fi]+=r.se,chkmin(mina[r.fi],now[r.fi]);
				if(r.se>0){
					for(int j=1;j<=r.se;j++) ans[v[p]]=ans[v[p]]*r.fi%cys;
				}
				else{
					ll inv=qpow(r.fi,cys-2);
					for(int j=1;j<=-r.se;j++) ans[v[p]]=ans[v[p]]*inv%cys;
				}
			}
		}
		else{
			ans[v[p]]=ans[u];
			for(auto r:vec[-c[p]]){
				now[r.fi]-=r.se,chkmin(mina[r.fi],now[r.fi]);
				if(r.se>0){
					ll inv=qpow(r.fi,cys-2);
					for(int j=1;j<=r.se;j++) ans[v[p]]=ans[v[p]]*inv%cys;
				}
				else{
					for(int j=1;j<=-r.se;j++) ans[v[p]]=ans[v[p]]*r.fi%cys;
				}
			}
		}
		dfs(v[p],u);
		if(c[p]>0){
			for(auto r:vec[c[p]]){
				now[r.fi]-=r.se,chkmin(mina[r.fi],now[r.fi]);
			}
		}
		else{
			for(auto r:vec[-c[p]]){
				now[r.fi]+=r.se,chkmin(mina[r.fi],now[r.fi]);
			}
		}
	}
}

int main(){
	int T=readint();
	getprime(200000);
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) h[i]=0; tot=0;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<=n;i++) ans[i]=1,mina[i]=now[i]=0;
		for(int i=1;i<n;i++){
			a[i].fi=readint(),a[i].se=readint();
			int x=readint(),y=readint(),g=__gcd(x,y);
			x/=g,y/=g;
			while(x>1){
				int tmp=p0[x],num=0;
				while(x%tmp==0) num++,x/=tmp;
				vec[i].pb(mp(tmp,-num));
			}
			while(y>1){
				int tmp=p0[y],num=0;
				while(y%tmp==0) num++,y/=tmp;
				vec[i].pb(mp(tmp,num));
			}
			addedge(a[i].fi,a[i].se,i);
		}
		dfs(1,-1);
//		for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
//		cout<<endl;
		ll res=0;
		for(int i=1;i<=n;i++) res=(res+ans[i])%cys;
//		for(int i=1;i<=n;i++) cout<<mina[i]<<' ';
//		cout<<endl;
		for(int i=1;i<=n;i++) for(int j=1;j<=-mina[i];j++) res=res*i%cys;
		printf("%lld\n",res);
	}
	return 0;
}