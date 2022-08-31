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

int n,tot,now;
int v[200005],nxt[200005],h[100005],du[100005];
vector<pii> ans;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[x]++;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot; du[y]++;
}

void dfs(int u,int fa,int t){
	int cm=t;
	ans.pb(mp(u,t));
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		du[v[p]]--;
		if(t!=now){
			t++;
			dfs(v[p],u,t);
		}
		else{
			t-=du[u]+1;
			ans.pb(mp(u,t));
			t++;
			dfs(v[p],u,t);
		}
		ans.pb(mp(u,t));
	}
	if(t+1!=cm&&u!=1){
		ans.pb(mp(u,cm-1));
		t=cm-1;
	}
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	for(int i=1;i<=n;i++) chkmax(now,du[i]);
	dfs(1,-1,0);
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	return 0;
}