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
const int N=200005,K=19;
int n,ti,lg[N<<1],zy[N],out[N],dep[N],in[N],q[N<<1],p[N],pos[N],dp[K][N<<1];
vector<int> v[N];
struct line{
	int x,y;
}tree[N<<2];
void dfs(int p){
	in[p]=++ti; q[++*q]=p; zy[p]=*q;
	for(auto i:v[p]){
		dep[i]=dep[p]+1; dfs(i); q[++*q]=p;
	}
	out[p]=ti;
}
#define cmp(a,b) (dep[a]<dep[b]?(a):(b))
#define check(a,b) (in[a]<=in[b]&&out[a]>=out[b])
inline int lca(int a,int b){
	a=zy[a]; b=zy[b];
    if(a>b)swap(a,b);
    int zs=lg[b-a+1];
    return cmp(dp[zs][b-(1<<zs)+1],dp[zs][a]);
}
line operator +(line a,line b){
	q[0]=a.x; q[1]=a.y; q[2]=b.x; q[3]=b.y;
	for(int i=0;i<4;i++)if(q[i]==-1)return tree[0];
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			int t=lca(q[i],q[j]),flag=0;
			for(int k=0;k<4;k++)if(k!=i&&k!=j){
				if(!(check(t,q[k])&&(check(q[k],q[i])||check(q[k],q[j]))))flag=1;
			}
			if(!flag)return (line){q[i],q[j]};
		}
	}
	return tree[0];
}
void build(int l,int r,int nod){
	if(l==r){
		if(!pos[l])tree[nod]=tree[0]; 
		else tree[nod]=(line){pos[l],pos[l]}; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	tree[nod]=tree[nod<<1]+tree[nod<<1|1];
}
void insert(int l,int r,int i,int nod){
	if(l==r){
		tree[nod]=(line){pos[l],pos[l]}; return;
	}
	int mid=(l+r)>>1;
	if(i<=mid)insert(l,mid,i,nod<<1); else insert(mid+1,r,i,nod<<1|1);
	tree[nod]=tree[nod<<1]+tree[nod<<1|1];
}
int find(int l,int r,line x,int nod){
	if(l==r)return l;
	int mid=(l+r)>>1; line y=x+tree[nod<<1];
	if(y.x==-1)return find(l,mid,x,nod<<1);
	else return find(mid+1,r,y,nod<<1|1);
}
int main(){
	tree[0]=(line){-1,-1};
	n=read();
	for(int i=1;i<=n;i++)pos[p[i]=read()]=i;
	for(int i=2;i<=n;i++)v[read()].push_back(i);
	dfs(1);
	lg[0]=-1;
	for(int i=1;i<=*q;i++){dp[0][i]=q[i]; lg[i]=lg[i>>1]+1;} 
	for(int i=1;(1<<i)<=*q;i++){
		for(int j=1;j+(1<<i)<=*q;j++){
			dp[i][j]=cmp(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
		}
	}
	build(0,n,1);
	int Tq=read();
	while(Tq--){
		int op=read();
		if(op==1){
			int x=read(),y=read();
			swap(p[x],p[y]);
			swap(pos[p[x]],pos[p[y]]);
			insert(0,n,p[x],1); insert(0,n,p[y],1);
		}else{
			writeln(find(0,n,(line){pos[0],pos[0]},1));
		}
	}
}
/*
6
5 2 3 4 1 0
1 1 1 3 3
1
2

dp[i]=a[i]+max(dp[j]+(x[i]-x[j])*y
*/