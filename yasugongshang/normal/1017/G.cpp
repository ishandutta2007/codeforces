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
const int N=100005;
bool clr[N<<2];
int n,q,f[N],top[N],ycl[N<<2],Ad[N<<2],tree[N<<2],in[N],out[N],fa[N],sz[N],dep[N];
vector<int> v[N];
void init(int l,int r,int nod){
	if(l==r){
		ycl[nod]=f[l]; tree[nod]=-f[l]; return;
	}
	int mid=(l+r)>>1;
	init(l,mid,nod<<1); init(mid+1,r,nod<<1|1);
	ycl[nod]=max(ycl[nod<<1],ycl[nod<<1|1]); tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
void Add(int nod,int x){
	Ad[nod]+=x; tree[nod]+=x;
}
void Clear(int nod){
	clr[nod]=1; Ad[nod]=0; tree[nod]=-ycl[nod];
}
void pushdown(int nod){
	if(clr[nod]){
		Clear(nod<<1); Clear(nod<<1|1); clr[nod]=0;
	}
	if(Ad[nod]){
		Add(nod<<1,Ad[nod]); Add(nod<<1|1,Ad[nod]); Ad[nod]=0;
	}
}
void add(int l,int r,int i,int j,int x,int nod){
	if(l==i&&r==j){
		Add(nod,x); return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)add(l,mid,i,j,x,nod<<1); else if(i>mid)add(mid+1,r,i,j,x,nod<<1|1);
	else{
		add(l,mid,i,mid,x,nod<<1); add(mid+1,r,mid+1,j,x,nod<<1|1);
	}
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
void clear(int l,int r,int i,int j,int nod){
	if(clr[nod]&&!Ad[nod])return;
	if(l==i&&r==j){
		Clear(nod); return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)clear(l,mid,i,j,nod<<1); else if(i>mid)clear(mid+1,r,i,j,nod<<1|1);
	else{
		clear(l,mid,i,mid,nod<<1); clear(mid+1,r,mid+1,j,nod<<1|1);
	}
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
int ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return tree[nod];
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1); else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return min(ask(l,mid,i,mid,nod<<1),ask(mid+1,r,mid+1,j,nod<<1|1));
}
inline bool cmp(int x,int y){
	return sz[x]>sz[y];
}
int ti;
void dfs(int p){
	sort(v[p].begin(),v[p].end(),cmp); in[p]=++ti; if(!top[p])top[p]=p;
	if(v[p].size())top[v[p][0]]=top[p]; dep[p]=dep[fa[p]]+1;
	for(unsigned i=0;i<v[p].size();i++)dfs(v[p][i]);
	out[p]=ti;
}
inline int qiu(int x){
	return x==0?0:ask(1,n,in[x],in[x],1);
}
inline int ask(int x){
	int ans=0;
	for(int i=x;i;i=fa[top[i]])ans=min(ans,ask(1,n,in[top[i]],in[i],1));
	return ans;
}
signed main(){
	n=read(); q=read();
	for(int i=2;i<=n;i++)v[fa[i]=read()].push_back(i);
	for(int i=n;i;i--)sz[fa[i]]+=++sz[i];
	dfs(1); for(int i=1;i<=n;i++)f[in[i]]=dep[i]; init(1,n,1);
	//for(int i=1;i<=n;i++)cout<<i<<" "<<qiu(i)<<" "<<dep[i]<<endl;
	for(int i=1;i<=q;i++){
		int op=read(),v=read();
		if(op==1)add(1,n,in[v],out[v],1,1);
		else if(op==2){
			int t=ask(fa[v]);
			clear(1,n,in[v],out[v],1);
			add(1,n,in[v],out[v],t-1+dep[v],1);
		}else{
			int t=ask(fa[v]);
			puts(t<=qiu(v)?"black":"white");
		}
		//for(int j=1;j<=n;j++)cout<<qiu(j)<<" "; puts("");
	}
}
/*
20 13
1 2 3 3 5 6 1 7 8 1 9 3 4 11 10 1 7 1 5 
1 5
2 9
2 8
1 3
1 5
1 8
1 9
2 6
3 6

*/