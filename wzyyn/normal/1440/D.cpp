#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
priority_queue<pii> Q;
vector<int> e[N];
int deg[N],vis[N];
int n,m,k;
const int moo=3000017;
struct Hashset{
	int head[moo];
	ll key[moo];
	int nxt[moo];
	int nd;
	Hashset(){
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		nd=0;
	}
	void init(){
		for (;nd;--nd) head[key[nd]%moo]=0;
	}
	void ins(ll v){
		key[++nd]=v;
		nxt[nd]=head[v%moo];
		head[v%moo]=nd;
	}
	bool chk(ll v){
		for (int i=head[v%moo];i;i=nxt[i])
			if (key[i]==v) return 1;
		return 0;
	}
}mmp;
vector<int> check(int x){
	vector<int> adj;
	adj.resize(0);
	for (auto i:e[x]) if (!vis[i]) adj.PB(i);
	For(i,0,adj.size()-1)
		For(j,i+1,adj.size()-1)
			if (!mmp.chk(1ll*adj[i]*N+adj[j]))
				return vector<int>{-1};
	adj.PB(x);
	return adj;
}
void solve(){
	mmp.init();
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) e[i].resize(0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
		mmp.ins(1ll*x*N+y);
		mmp.ins(1ll*y*N+x);
	}
	if (1ll*k*(k-1)/2>m)
		return puts("-1"),void(0);
	For(i,1,n) deg[i]=e[i].size();
	For(i,1,n) vis[i]=0;
	while (!Q.empty()) Q.pop();
	For(i,1,n) Q.push(pii(-deg[i],i));
	int rem=n;
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue;
		//cout<<x<<' '<<deg[x]<<endl;
		if (deg[x]>=k){
			printf("1 %d\n",rem);
			For(i,1,n) if (!vis[i]) printf("%d ",i);
			puts("");
			return;
		}
		if (deg[x]==k-1){
			vector<int> temp=check(x);
			if (temp[0]!=-1){
				printf("%d\n",2);
				for (auto i:temp) printf("%d ",i);
				puts("");
				return;
			}
		}
		--rem;
		vis[x]=1;
		for (auto i:e[x])
			if (!vis[i])
				Q.push(pii(-(--deg[i]),i));
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}