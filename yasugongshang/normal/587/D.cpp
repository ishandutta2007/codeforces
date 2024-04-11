#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=50005,NN=10*N,MM=25*N,inf=1e9;
vector<int> jb[N],e[NN];
int n,m,qlt,ti,ne,top,u[N],v[N],c[N],t[N];
int dfn[NN],rd[NN],low[NN],to[NN],ans[NN],zhan[NN],zh[NN],son[NN];
int ed[MM],nxt[MM];
inline int yi(int x){return (x&1)?x+1:x-1;}
bool cmp(int x,int y){
	return c[x]<c[y];
}
void ae(int a,int b){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b;
}
void ins(int a,int b){
	//cout<<a<<" "<<b<<endl;
	ae(a,b); ae(yi(b),yi(a));
}
void dfs(int p){
	dfn[p]=low[p]=++ti;
	zhan[++top]=p; zh[p]=1;
	for(int i=son[p];i;i=nxt[i])if(!dfn[ed[i]]){
		dfs(ed[i]); low[p]=min(low[p],low[ed[i]]);
	}else if(zh[ed[i]])low[p]=min(low[p],dfn[ed[i]]);
	if(dfn[p]==low[p]){
		qlt++;
		while(1){
			to[zhan[top]]=qlt; zh[zhan[top]]=0;
			if(zhan[top--]==p)break;
		}
	}
}
int dq;
bool check(int x){
	memset(son,0,sizeof(son)); memset(dfn,0,sizeof(dfn)); 
	
	ti=ne=qlt=0;
	dq=2*m;
	For(i,1,n)if(jb[i].size()){
		int len=jb[i].size();
		dq+=2; ins(dq,2*jb[i][0]); 
		For(j,1,len-1){
			dq+=2; ins(dq,dq-2); ins(2*jb[i][j]-1,dq-2);
			ins(dq,2*jb[i][j]);
		}
	}
	For(i,1,n)if(jb[i].size()){
		int len=jb[i].size();
		for(int j=0,dd;j<len;){
			dd=j+1; while(dd<len&&c[jb[i][dd]]==c[jb[i][j]])dd++;
			dq+=2; ins(dq,2*jb[i][j]-1); j++;
			while(j<dd){
				dq+=2; ins(dq,dq-2); ins(2*jb[i][j],dq-2);
				ins(dq,2*jb[i][j]-1); j++;
			}
		}
	}
	For(i,1,m)if(t[i]>x)ae(2*i-1,2*i); 
	For(i,1,dq)if(!dfn[i])dfs(i);
	//For(i,1,dq)wri(to[i]); exit(0);
	for(int i=1;i<=dq;i+=2)if(to[i]==to[i+1])return 0;
	return 1;
}
void solve(int x){
	check(x); queue<int> q;
	For(i,1,dq)for(int j=son[i];j;j=nxt[j])if(to[i]!=to[ed[j]]){e[to[i]].pb(to[ed[j]]); rd[to[ed[j]]]++;}
	For(i,1,qlt)if(!rd[i])q.push(i); int zyk=0;
	while(q.size()){
		int t=q.front(); q.pop(); ans[t]=++zyk; //if(t<=14)cout<<t<<endl;
		for(auto i:e[t])if(--rd[i]==0)q.push(i);
	}
	vector<int> vvv;
	//For(i,1,m)if(ans[to[i*2-1]]>ans[to[i*2]])cout<<ed[son[i*2-1]]<<" "<<t[i]<<endl;
	For(i,1,m)if(ans[to[i*2-1]]>ans[to[i*2]])vvv.pb(i);
	writeln(vvv.size());
	for(auto i:vvv)wri(i); 
}
int main(){
	n=read(),m=read();
	For(i,1,m){
		u[i]=read(); v[i]=read(); c[i]=read(); t[i]=read();
		jb[u[i]].pb(i); jb[v[i]].pb(i);
	}
	For(i,1,n)sort(jb[i].begin(),jb[i].end(),cmp);
	//cout<<check(3)<<endl; return 0;
	int l=0,r=inf+1;
	while(l<r){
		int mid=(l+r)>>1; 
		if(check(mid))r=mid; else l=mid+1;
	}
	if(l>inf)puts("No"); else{
		puts("Yes");
		wri(l);
		solve(l);
	}
}