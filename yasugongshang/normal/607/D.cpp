#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
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
const int N=200005,M=N<<2,mod=1000000007;
int n,q,d[N],V[N],Q[N],op[N],fa[N],jb[N],in[N],out[N],ti;
vector<int> v[N];
ll tree[M],lazy[M];
void push_up(int nod){
	tree[nod]=(tree[nod<<1]+tree[nod<<1|1])%mod;
}
void cao(int nod,ll x){
	tree[nod]=tree[nod]*x%mod; lazy[nod]=lazy[nod]*x%mod; 
}
void alb(int nod,ll x){
	tree[nod]=(tree[nod]+x*lazy[nod])%mod;
}
void pushdown(int nod){
	cao(nod<<1,lazy[nod]); cao(nod<<1|1,lazy[nod]);
	lazy[nod]=1;
}
void insert(int l,int r,int i,int j,ll x,int nod){
	if(l==i&&r==j){
		cao(nod,x); return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)insert(l,mid,i,j,x,nod<<1); else if(i>mid)insert(mid+1,r,i,j,x,nod<<1|1);
	else{
		insert(l,mid,i,mid,x,nod<<1); insert(mid+1,r,mid+1,j,x,nod<<1|1);
	}
	push_up(nod);
}
void add(int l,int r,int pos,ll de,int nod){
	if(l==r){
		alb(nod,de); return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(pos<=mid)add(l,mid,pos,de,nod<<1); else add(mid+1,r,pos,de,nod<<1|1);
	push_up(nod);
}
ll ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return tree[nod];
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1); else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return (ask(l,mid,i,mid,nod<<1)+ask(mid+1,r,mid+1,j,nod<<1|1))%mod;
}
ll bao(int l,int r,int pos,int nod){
	if(l==r)return lazy[nod];
	pushdown(nod);
	int mid=(l+r)>>1;
	if(pos<=mid)return bao(l,mid,pos,nod<<1); else return bao(mid+1,r,pos,nod<<1|1);
}
void dfs(int p){
	in[p]=++ti;
	for(auto i:v[p])dfs(i);
	out[p]=ti;
}
inline ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
inline ll ni(ll x){
	return ksm(x,mod-2);
}
int main(){
	for(int i=1;i<M;i++)lazy[i]=1;
	V[n=1]=read(); q=read();
	for(int i=1;i<=q;i++){
		op[i]=read();
		if(op[i]==1){
			fa[++n]=read(); jb[i]=n; V[n]=read();
		}else{
			Q[i]=read();
		}
	}
	for(int i=2;i<=n;i++)v[fa[i]].push_back(i);
	dfs(1);
	for(int i=1;i<=n;i++)d[i]=1;
	add(1,n,in[1],V[1],1);
	for(int i=1;i<=q;i++){
		if(op[i]==1){
			ll t=(ll)(d[fa[jb[i]]]+1)*ni(d[fa[jb[i]]])%mod; d[fa[jb[i]]]++;
			insert(1,n,in[fa[jb[i]]],out[fa[jb[i]]],t,1);
			add(1,n,in[jb[i]],V[jb[i]],1);
		}else{
			ll t1=ask(1,n,in[Q[i]],out[Q[i]],1);
			ll t2=Q[i]==1?1:bao(1,n,in[fa[Q[i]]],1);
			writeln(t1*ni(t2)%mod);
		}
	}
	//cout<<ask(1,n,in[2],out[2],1)<<" "<<bao(1,n,1,1)<<endl;
}
/*
i j sum[i]/sum[j]*x
sum 
*/