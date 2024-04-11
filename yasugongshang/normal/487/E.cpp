#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=200005,M=200005,inf=1000000005;
int n,m,Q,V,top[N],tree[N<<2],dep[N],wson[N],a[N],in[N],out[N],peo[N],dfn[N],low[N],father[N],ti,sta[N],st;
int nextt[M],ed[M],son[N],nedge;
char ch[10];
struct heap{
	priority_queue<int,vector<int>,greater<int> > q1,q2;
	void push(int x){
		q1.push(x);
	}
	void erase(int x){
		q2.push(x);
	}
	int top(){
		while(q1.size()&&q2.size()&&q1.top()==q2.top()){
			q1.pop(); q2.pop();
		}
		return q1.size()?q1.top():inf;
	}
}q[N];
void aedge(int a,int b){
	if(!nedge)nedge=1;
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; 
}
void add(int a,int b){
	aedge(a,b); aedge(b,a);
}

vector<int> e[N];
void tarjan(int p,int fa){
	dfn[p]=low[p]=++ti; sta[++st]=p; 
	for(int i=son[p];i;i=nextt[i])if((i^fa)!=1){
		int v=ed[i];
		if(!dfn[v]){
			tarjan(v,i); low[p]=min(low[p],low[v]);
			if(low[v]>=dfn[p]){
				e[p].push_back(++V);
				int x=0;
				do{
					x=sta[st--];
					e[V].push_back(x);
					father[x]=V;
				}while(x^v);
				father[V]=p;
			}
		}else low[p]=min(low[p],dfn[v]);
	}
}
void dfs1(int p){
	peo[p]=1;
	for(unsigned i=0;i<e[p].size();i++){
		dep[e[p][i]]=dep[p]+1; dfs1(e[p][i]);
		peo[p]+=peo[e[p][i]]; 
		if(!wson[p]||peo[e[p][i]]>peo[wson[p]])wson[p]=e[p][i];
	}
}
void dfs2(int p){
	in[p]=++ti;
	if(wson[father[p]]==p)top[p]=top[father[p]]; else top[p]=p;
	if(wson[p])dfs2(wson[p]);
	for(unsigned i=0;i<e[p].size();i++)if(e[p][i]!=wson[p])dfs2(e[p][i]);
	out[p]=ti;
}
void insert(int l,int r,int pos,int nod){
	if(l==r){
		tree[nod]=q[pos].top(); return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,nod<<1); else insert(mid+1,r,pos,nod<<1|1);
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
int ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return tree[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1); else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return min(ask(l,mid,i,mid,nod<<1),ask(mid+1,r,mid+1,j,nod<<1|1));
}
void build(int l,int r,int nod){
	if(l==r){
		tree[nod]=q[l].top(); return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
int query(int x,int y){
	int ans=inf;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=min(ans,ask(1,V,in[top[x]],in[x],1));
		x=father[top[x]];
	}
	if(in[x]>in[y])swap(x,y);
	ans=min(ans,ask(1,V,in[x],in[y],1));
	if(x>n)ans=min(ans,a[father[x]]); else ans=min(ans,a[x]);
	return ans;
}
int main(){
	n=read(); m=read(); V=n; Q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		add(s,t);
	}
	tarjan(1,0); ti=0;
	dfs1(1); dfs2(1);
	for(int i=1;i<=n;i++)q[in[father[i]]].push(a[i]); 
	build(1,V,1); 
	while(Q--){
		scanf("%s",ch);
		if(ch[0]=='C'){
			int x=read(),y=read(),t=q[in[father[x]]].top();
			q[in[father[x]]].erase(a[x]);
			q[in[father[x]]].push(a[x]=y);
			if(q[in[father[x]]].top()!=t)insert(1,V,in[father[x]],1);
		}else{
			int x=read(),y=read();
			writeln(query(x,y));
		}
	}
}