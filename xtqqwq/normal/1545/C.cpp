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

const int cys=998244353;
int n,tot;
int b[505][505],c[505][505],a[1005][505],v[500005],nxt[500005],h[1005],col[1005];
bool vis[1005],hv[505][505],cho[1005];
queue<pii> q;
vector<int> vec[505][505];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]||col[v[p]]>=0) continue;
		col[v[p]]=col[u]^1;
		dfs(v[p]);
	}
}

void erase(int id){
	if(vis[id]) return;
	for(int i=1;i<=n;i++){
		b[i][a[id][i]]--,c[i][a[id][i]]-=id;
		if(b[i][a[id][i]]==1&&!hv[i][a[id][i]]) q.push(mp(i,a[id][i]));
	}
	vis[id]=1;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) b[i][j]=c[i][j]=0,vec[i][j].clear();
		for(int i=1;i<=n+n;i++) vis[i]=cho[i]=0;
		for(int i=1;i<=n+n;i++){
			for(int j=1;j<=n;j++) a[i][j]=readint();
			for(int j=1;j<=n;j++) b[j][a[i][j]]++,c[j][a[i][j]]+=i,vec[j][a[i][j]].pb(i);
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(b[i][j]==1) q.push(mp(i,j));
		int cnt=0;
		while(!q.empty()){
			pii t=q.front(); q.pop();
			int pl=c[t.fi][t.se];
			if(!pl||vis[pl]) continue;
			vis[pl]=cho[pl]=1;
			for(int i=1;i<=n;i++){
				b[i][a[pl][i]]--,c[i][a[pl][i]]-=pl;
				for(auto r:vec[i][a[pl][i]]) if(!vis[r]) erase(r);
			}
		}
		for(int i=1;i<=n+n;i++) h[i]=0; tot=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int pl0=0,pl1=0;
				for(auto r:vec[i][j]){
					if(vis[r]) continue;
					if(!pl0) pl0=r;
					else pl1=r;
				}
				if(pl0) addedge(pl0,pl1);
			}
		}
		for(int i=1;i<=n+n;i++) col[i]=-1;
		for(int i=1;i<=n+n;i++){
			if(vis[i]) continue;
			if(col[i]<0){
				cnt++;
				col[i]=0;
				dfs(i);
			}
		}
		printf("%lld\n",qpow(2,cnt));
		vector<int> res(0);
		for(int i=1;i<=n+n;i++) if(cho[i]) res.pb(i);
		for(int i=1;i<=n+n;i++) if(col[i]==0) res.pb(i);
		sort(res.begin(),res.end());
		for(auto r:res) printf("%d ",r);
		printf("\n");
	}
	return 0;
}