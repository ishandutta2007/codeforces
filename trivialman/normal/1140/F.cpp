#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define lson id<<1,l,mid
#define rson id<<1|1,mid+1,r
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 6e5+10;

int fa[N],sz1[N],sz2[N],q,x,y,top=0;
int dsu1[N],dsu2[N];
map<int, int> mp[N>>1];
vector<PII> e[N<<1];

void ins(int from, int to, PII p, int id=1, int l=1, int r=q){
	if(from<=l && to>=r){
		e[id].PB(p);
		return;
	}
	int mid=l+r>>1;
	if(mid>=from) ins(from,to,p,lson);
	if(mid<to) ins(from,to,p,rson);
}

int find(int x){return x==fa[x]?x:find(fa[x]);}

void dfs(int id=1, int l=1, int r=q, LL ans=0){
	int now=top;
	for(auto p:e[id]){
		int x=find(p.first),y=find(p.second);
		if(x==y)continue;
		if(sz1[x]+sz2[x]<sz1[y]+sz2[y]) swap(x,y);
		ans = ans + 1ll * sz1[x] * sz2[y] + 1ll * sz1[y] * sz2[x];
		sz1[x] += sz1[y]; sz2[x] += sz2[y];
		dsu1[++top] = x, dsu2[top] = y;
		fa[y] = x;
	}
	if(l==r){
		printf("%lld ", ans); return;
	}
	int mid = l+r>>1;
	dfs(lson, ans); dfs(rson, ans); 
	for(;top>now;--top){
		sz1[dsu1[top]] -= sz1[dsu2[top]], sz2[dsu1[top]] -= sz2[dsu2[top]];
		fa[dsu2[top]] = dsu2[top];
	} 
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	memset(sz1,0,sizeof sz1);memset(sz2,0,sizeof sz2);
	rep(i,1,6e5)fa[i]=i,(i<=3e5?sz1:sz2)[i]=1;
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%d%d",&x,&y);
		y+=3e5;
		if(mp[x][y])
			ins(mp[x][y],i-1,MP(x,y)),mp[x][y]=0;
		else mp[x][y]=i;
	}
	rep(i,1,3e5) for(auto u:mp[i]) if(u.second) ins(u.second,q,MP(i,u.first));
	dfs();
	return 0;
}