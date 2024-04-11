#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 2e5;
const int M = 2e5;
const int TN = N << 2;
const ll inf = 0x3f3f3f3f3f3f3f3f;

typedef pair<ll,int> pli;

namespace IO{
	In ll read(){ 
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int n,m,q;

//SegTree
struct SegTree{
	ll f[TN+5];
	void init(){
		f[1] = inf;
	}
	In void pushdown(int u){
		if(!f[u])return;
		f[glc(u)] = f[grc(u)] = f[u];
		f[u] = 0;
	}
	void ud(int u,int l,int r,int ql,int qr,ll x){
		if(l == ql && r == qr){
			f[u] = x;return;
		}
		int m = (l + r) >> 1;
		pushdown(u);
		if(qr <= m)ud(glc(u),l,m,ql,qr,x);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr,x);
		else ud(glc(u),l,m,ql,m,x),ud(grc(u),m + 1,r,m + 1,qr,x);
	}
	ll query(int u,int l,int r,int pos){
		if(l == r)return f[u];
		int m = (l + r) >> 1;
		pushdown(u);
		if(pos <= m)return query(glc(u),l,m,pos);
		else return query(grc(u),m + 1,r,pos);
	}
}T;

//graph
struct edge{
	int u,v,next;ll w;
}e[2*M+5];

int head[N+5];
int cnt;

In void addedge(int a,int b,ll w){
	cnt++;
	e[cnt].u = a;
	e[cnt].v = b;
	e[cnt].w = w;
	e[cnt].next = head[a];
	head[a] = cnt;
}

ll dis1[N+5],disn[N+5],last[N+5];

priority_queue<pli,vector<pli>,greater<pli> > pq;

void dij(int s,ll dis[]){
	for(rg int i = 1;i <= n;i++)dis[i] = inf;
	dis[s] = 0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		pli p = pq.top();
		pq.pop();
		int u = p.second;
		if(dis[u] != p.first)continue;
		for(rg int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(dis[u] + e[i].w < dis[v]){
				if(s == 1)last[v] = i;
				dis[v] = dis[u] + e[i].w;
				pq.push(make_pair(dis[v],v));
			}
		}
	}
}

//solve
int ave[N+5],point[N+5],num[M+5],An;
int l[N+5],r[N+5];
bool imp[2*M+5];
stack<int>s;

void dfs1(int u,int id){
	if(l[u])return;
	l[u] = id;	
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].v;
		if(imp[i] || dis1[u] + e[i].w != dis1[v])continue;
		dfs1(v,id);
	}
}

void dfsn(int u,int id){
	if(r[u])return;
	r[u] = id;
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].v;
		if(imp[i] || disn[u] + e[i].w != disn[v])continue;
		dfsn(v,id);
	}
}

void prepro(){
	for(rg int u = n;u != 1;u = e[last[u]].u)s.push(last[u]);
	while(!s.empty())ave[++An] = s.top(),s.pop();
	for(rg int i = 1;i <= An;i++)imp[ave[i]] = imp[ave[i]^1] = 1,num[ave[i]>>1] = i;
	for(rg int i = 1;i <= An;i++)point[i] = e[ave[i]].u;
	point[An+1] = e[ave[An]].v;
	for(rg int i = 1;i <= An + 1;i++)dfs1(point[i],i);
	for(rg int i = An + 1;i >= 1;i--)dfsn(point[i],i);
}

struct node{
	int l,r;ll cur;
	node(){l = r = cur = 0;}
	node(int _l,int _r,ll _cur){l = _l,r = _r,cur = _cur;}
}mdf[2*M+5];
int Mn;

In bool cmp(node a,node b){
	return a.cur > b.cur;
}

void solve(){
	for(rg int i = 2;i <= cnt;i++)if(!imp[i]){
		int u = e[i].u;
		int v = e[i].v;
		if(!l[u] || !r[v] || l[u] >= r[v])continue;
		ll cur = dis1[u] + disn[v] + e[i].w;
		mdf[++Mn] = node(l[u],r[v] - 1,cur);		
	}
	sort(mdf + 1,mdf + Mn + 1,cmp);
	T.init();
	for(rg int i = 1;i <= Mn;i++){
//cout<<"l="<<mdf[i].l<<" r="<<mdf[i].r<<" cur="<<mdf[i].cur<<endl;	
		T.ud(1,1,An,mdf[i].l,mdf[i].r,mdf[i].cur);
	}
}

int main(){
//	freopen("CF1163F.in","r",stdin);
 //	freopen("CF1163F.out","w",stdout);
 

	cnt = 1;
	n = read(),m = read();q = read();
	for(rg int i = 1;i <= m;i++){
		int u = read(),v = read();ll w = read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	
	dij(1,dis1);
	dij(n,disn);

	prepro();
	solve();
	
	for(rg int i = 1;i <= q;i++){
		int id = read();ll x = read();
		ll ans;
		if(num[id]){
			if(x <= e[id<<1].w)ans = dis1[n] - e[id<<1].w + x;
			else{
				ll ans1 = dis1[n] - e[id<<1].w + x;
				ll ans2 = T.query(1,1,An,num[id]);
				ans = min(ans1,ans2);
			}
		}
		else{
			if(x > e[id<<1].w)ans = dis1[n];
			else{
				ll ans1 = dis1[n];
				int u = e[id<<1].u;
				int v = e[id<<1].v;
				ll ans2 = min(dis1[u] + x + disn[v],dis1[v] + x + disn[u]);
				ans = min(ans1,ans2);
			}
		}
		write(ans),putchar('\n');
	}

	return 0;
}