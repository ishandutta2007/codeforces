#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
const int N=500005,K=51;
PI q[N];
int top,n,m,Q,k,to[N],a[N],b[N],c[N],e[N],col[N],nxt[N];
vector<int> v[1<<20|2];
struct bit{
	int fa[N],sz[N],v[N];
	inline int gf(int x){
		return fa[x]==x?x:gf(fa[x]);
	}
	inline int gv(int x){
		return fa[x]==x?0:v[x]^gv(fa[x]);
	}
	bool check(int a,int b){
		return gf(a)!=gf(b)||gv(a)!=gv(b);
	}
	void mer(int &a,int &b,int x){
		if(sz[a]>sz[b])swap(a,b);
		fa[a]=b; v[a]=x^1;
		sz[b]+=sz[a];
	}
	void clear(int x){
		sz[fa[x]]-=sz[x];
		v[x]=0; fa[x]=x;
	}
}T[K];
bool check(int a,int b,int id){
	return T[id].check(a,b);
}
void mer(int a,int b,int id){
	int x=T[id].gv(a)^T[id].gv(b);
	a=T[id].gf(a); b=T[id].gf(b);
	if(a!=b){
		T[id].mer(a,b,x);
		q[++top]=mp(id,a);
	}
}
void clear(int zs){
	while(top>zs){
		int id=q[top].fi,x=q[top--].se;
		T[id].clear(x);
	}
}
void ins(int l,int r,int i,int j,int x,int nod){
	if(l==i&&r==j)return v[nod].pb(x); 
	int mid=(l+r)>>1;
	if(j<=mid)ins(l,mid,i,j,x,nod<<1); else
	if(i>mid)ins(mid+1,r,i,j,x,nod<<1|1); else{
		ins(l,mid,i,mid,x,nod<<1); ins(mid+1,r,mid+1,j,x,nod<<1|1);
	}
}
void solve(int l,int r,int nod){
	int zs=top;
	for(auto i:v[nod]){
		mer(a[e[i]],b[e[i]],c[i]);
	}
	if(l==r){
		if(check(a[e[l]],b[e[l]],c[l])){
			puts("YES"); col[e[l]]=c[l];
		}else{
			c[l]=col[e[l]];
			puts("NO");
		} //cout<<l<<" "<<r<<" "<<nod<<endl;
		if(l<Q&&c[l])ins(1,Q,l+1,nxt[l],l,1); clear(zs); return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,nod<<1); solve(mid+1,r,nod<<1|1);
	clear(zs);
}
int main(){
	n=read(),m=read(),k=read(),Q=read();
	For(i,1,m){
		a[i]=read(); b[i]=read();
	}
	For(i,1,Q){
		e[i]=read(); c[i]=read();
		if(to[e[i]])nxt[to[e[i]]]=i;
		to[e[i]]=i;
	}
	For(i,1,m)if(to[i])nxt[to[i]]=Q;
	For(i,1,k)For(j,1,n)T[i].sz[T[i].fa[j]=j]=1; 
	solve(1,Q,1);
}