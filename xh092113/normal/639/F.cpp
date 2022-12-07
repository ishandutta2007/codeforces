#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 3e5;
const int M = 3e5;

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
};
using namespace IO;

int n,m,q,tempn,tempm;
int fa[N+5][19],dep[N+5];

//// Virtual Tree

bool vis[N+5];
int p[3*N+5],pn;
int st[N+5],top;
int tempv[N+5];
int cnt2,head2[N+5];
int low2[N+5],dfn2[N+5],Dn2;
vector<int> vc;
pair<int,int> tempe[N+5];
queue<int> Q2;

struct edge{ 
	int next,to,cut;
}E[4*N+5];

In void Addedge(int u,int v){
	cnt2++;
	E[cnt2].to = v;
	E[cnt2].next = head2[u];
	E[cnt2].cut = 0;
	head2[u] = cnt2;
}
In void Add(int u,int v){
	vc.push_back(u);vc.push_back(v);
	Addedge(u,v);
	Addedge(v,u);
}
int getlca(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	for(rg int i = 18;i >= 0;i--)if(dep[fa[u][i]] >= dep[v])u = fa[u][i];
	if(u == v)return u;
	for(rg int i = 18;i >= 0;i--)if(fa[u][i] != fa[v][i])u = fa[u][i],v = fa[v][i];
	return fa[u][0];
}
void tarjan2(int u,int pree){
	low2[u] = dfn2[u] = ++Dn2;
	for(rg int i = head2[u];i;i = E[i].next)if(i != (pree^1)){
		int v = E[i].to;if(v == 0)continue;
		if(dfn2[v])low2[u] = min(low2[u],dfn2[v]);
		else{
			tarjan2(v,i);
			low2[u] = min(low2[u],low2[v]);
			if(low2[v] > dfn2[u])E[i].cut = E[i^1].cut = 1;
		}
	}
}
void bfs2(int s){
	Q2.push(s);vis[s] = 1;
	while(!Q2.empty()){
		int u = Q2.front();Q2.pop();
		for(rg int i = head2[u];i;i = E[i].next){
			int v = E[i].to;
			if(v == 0 || E[i].cut || vis[v])continue;
			vis[v] = 1;
			Q2.push(v);
		}
	}
}
bool Solve(){
	Dn2 = 0;
	for(rg int i = 1;i <= tempm;i++)Add(tempe[i].first,tempe[i].second);
	for(rg int i = head2[0];i;i = E[i].next){
		tarjan2(E[i].to,i);
	}
//for(rg int i = 1;i <= n;i++)cout<<dfn2[i]<<" ";cout<<endl;
	
/*(for(rg int u = 0;u <= n;u++){
	cout<<"u="<<u<<endl;
	for(rg int i = head2[u];i;i = E[i].next){
		int v = E[i].to;
		cout<<" v="<<v<<" cut="<<E[i].cut<<endl;
	}
}*/
	bfs2(tempv[1]);
	for(rg int i = 1;i <= tempn;i++)if(!vis[tempv[i]])return 0;
	return 1;
}
void clear(){
	top = 0;cnt2 = 1;
	for(rg int i = 0;i < vc.size();i++){
		int u = vc[i];
		vis[u] = head2[u] = dfn2[u] = 0;
	}
	vc.resize(0);
}

//// Tree after BCC mergence

int bn,Dn,bcc[N+5],dfn[N+5];
vector<int> t[N+5];

In bool cmp(int u,int v){return dfn[u] < dfn[v];}
void buildVT(){
	vc.push_back(0);
	st[top=1] = 0;
//for(rg int i = 1;i <= pn;i++)cout<<p[i]<<" ";cout<<endl;
	sort(p + 1,p + pn + 1,cmp);
	pn = unique(p + 1,p + pn + 1) - p - 1;
//for(rg int i = 1;i <= pn;i++)cout<<p[i]<<" ";cout<<endl;
	for(rg int i = 1;i <= pn;i++){
		int u = p[i],lca = getlca(u,st[top]);
		if(lca == st[top])st[++top] = u;
		else{
			while(top && dep[lca] < dep[st[top-1]]){
				Add(st[top-1],st[top]);
				top--;
			}
			if(lca == st[top-1]){
				Add(st[top-1],st[top]);
				st[top] = u;
			}
			else{
				Add(lca,st[top]);
				st[top] = lca,st[++top] = u;
			}
		}
	}
	for(rg int i = 1;i < top;i++)Add(st[i],st[i+1]);
/*cout<<"Virtual Tree Construction Complete"<<endl;
for(rg int u = 0;u <= pn;u++){
cout<<"u="<<u<<endl;
	for(rg int i = head2[u];i;i = E[i].next)cout<<E[i].to<<" ";cout<<endl; 
}*/
}
In int rotate(int element,ll R){
	element=(element+R)%n;
	if (element==0)element=n;
  	return element;
}
int solve(ll R){ // never use memset in this part
// CLEAR
	tempn = read(),tempm = read();
//cout<<"tempn="<<tempn<<" tempm="<<tempm<<endl;
	pn = 0;
//cout<<"solve: R="<<R<<endl;
	for(rg int i = 1;i <= tempn;i++)tempv[i] = p[++pn] = bcc[rotate(read(),R)];
//for(rg int i = 1;i <= tempn;i++)cout<<tempv[i]<<" ";cout<<endl;
	for(rg int i = 1;i <= tempm;i++){
		int u = bcc[rotate(read(),R)],v = bcc[rotate(read(),R)];
		tempe[i] = make_pair(u,v);
		p[++pn] = u,p[++pn] = v;
//cout<<u<<" "<<v<<endl;
	}
	clear();
	buildVT();
	bool b = Solve();if(b)puts("YES");else puts("NO");
	return b;
}
void dfs2(int u,int ff){
	Dn++;dfn[u] = Dn;
	fa[u][0] = ff;
	for(rg int i = 0;i < t[u].size();i++){
		int v = t[u][i];
		if(v == ff)continue;
		dep[v] = dep[u] + 1;
		dfs2(v,u);
	}
}

//// Initial graph

int cnt,head[N+5];
int low[N+5];
edge e[2*M+N+10];
queue<int> Q;

In void addedge(int a,int b){
	cnt++;
	e[cnt].to = b;
	e[cnt].next = head[a];
	e[cnt].cut = 0;
	head[a] = cnt;
}
void tarjan(int u,int ff,int pree){
	dfn[u] = ++Dn;
	low[u] = dfn[u];
	for(rg int i = head[u];i;i = e[i].next)if(i != (pree^1)){
		int v = e[i].to;
		if(dfn[v])low[u] = min(low[u],dfn[v]);
		else{
			tarjan(v,u,i);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u])e[i].cut = e[i^1].cut = 1;
		}
	}
}
void bfs(int s,int bid){
	Q.push(s);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(rg int i = head[u];i;i = e[i].next){
			int v = e[i].to;
			if(e[i].cut || bcc[v])continue;
			bcc[v] = bid;
			Q.push(v);
		}
	}
}
void buildTree(){
	for(rg int i = 1;i <= n;i++)if(!bcc[i]){
		bcc[i] = ++bn;
		bfs(i,bn);
	}
	for(rg int u = 0;u <= n;u++){
		for(rg int i = head[u];i;i = e[i].next)if(e[i].cut){
			t[bcc[u]].push_back(bcc[e[i].to]);
		}
	}
}

int main(){
//	freopen("CF639F.in","r",stdin);
//	freopen("CF639F.out","w",stdout);
// MULTIPLE CASES
// TIME COMPLEXITY
// MEMORY LIMIT
// ARRAY SIZE
	ll R = 0,Tc;
	n = read(),m = read(),Tc = read();
	cnt = 1;
	for(rg int i = 1;i <= m;i++){
		int u = read(),v = read();
		addedge(u,v);
		addedge(v,u);
	}
	for(rg int u = 1;u <= n;u++)if(!dfn[u]){
		addedge(0,u),e[cnt].cut = 1;
		tarjan(u,0,0);
	}
	buildTree();
	Dn = 0;dfs2(0,0);
	for(rg int i = 1;i <= 18;i++){
		for(rg int u = 1;u <= bn;u++)fa[u][i] = fa[fa[u][i-1]][i-1];
	}
//for(rg int i = 0;i <= n;i++)cout<<bcc[i]<<" ";cout<<endl;
//for(rg int i = 0;i <= bn;i++)cout<<"i="<<i<<" fa="<<fa[i][0]<<" dep="<<dep[i]<<" dfn="<<dfn[i]<<endl;
	for(rg int t = 1;t <= Tc;t++){
		if(solve(R))R += t;
	}
	return 0;
}