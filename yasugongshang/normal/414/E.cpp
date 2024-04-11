#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define ld long double
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
const int N=200005;
int n,m,rt,tong[N],w[N],W[N],in[N],out[N],tot,s[N],S[N],ch[N][2],dep[N],fa[N],lazy[N];
vector<int> v[N];
inline bool get(int x){
	return ch[fa[x]][1]==x;
}
inline void cao(int x,int y){
	w[x]+=y; W[x]+=y; s[x]+=y; S[x]+=y; lazy[x]+=y;
}
void pushdown(int x){
	if(lazy[x]){
		if(ch[x][0])cao(ch[x][0],lazy[x]); if(ch[x][1])cao(ch[x][1],lazy[x]); lazy[x]=0;
	}
}
inline void update(int x){
	s[x]=w[x]; S[x]=W[x]; 
	if(ch[x][0]){s[x]=min(s[x],s[ch[x][0]]); S[x]=max(S[x],S[ch[x][0]]);}
	if(ch[x][1]){s[x]=min(s[x],s[ch[x][1]]); S[x]=max(S[x],S[ch[x][1]]);}
}
inline void rotate(int x){
    int y=fa[x],z=fa[y],o=get(x);
    if(z)ch[z][get(y)]=x;
    ch[y][o]=ch[x][o^1]; if(ch[y][o])fa[ch[y][o]]=y;
    ch[x][o^1]=y; fa[y]=x; fa[x]=z;
    update(y); update(x);
}
void push(int x){
	if(fa[x])push(fa[x]);
	pushdown(x);
}
void splay(int x,int k){
    push(x);
	for(int y,z;fa[x]!=k;rotate(x)){
    	y=fa[x]; z=fa[y];
    	if (z!=k)rotate((get(z)^get(y))?x:y);
 	}
    if(!k)rt=x;
}
void Update(int x){
	splay(x,0);
}
void insert(int x,int y){
	splay(x,0); 
	if(!ch[x][0]){
		push(x); ch[x][0]=y; fa[y]=x; update(x); return;
	}
	x=ch[x][0]; while(ch[x][1])x=ch[x][1]; push(x);
	ch[x][1]=y; fa[y]=x; Update(x);
}
int Alb(int x,bool id){
	splay(x,0);	x=ch[x][id];
	while(ch[x][id^1])x=ch[x][id^1];
	return x;
}
bool check(int l,int r){
	splay(l,0); splay(r,0); 
	return ch[r][0]==l;
}
int get(int l,int r){
	if(check(r,l))swap(l,r); 
	int L=Alb(l,0),R=Alb(r,1);
	splay(L,0); splay(R,rt);
	return ch[R][0];
}
void dfs(int p){
	in[p]=++tot; s[tot]=S[tot]=w[tot]=W[tot]=dep[p]; tong[tot]=p;
	for(auto i:v[p]){dep[i]=dep[p]+1; dfs(i);}
	out[p]=++tot; s[tot]=S[tot]=w[tot]=W[tot]=dep[p]; tong[tot]=p;
}
inline int getdep(int x){
	x=in[x]; splay(x,0);
	return w[x];
}
int find(int x,int k){
	pushdown(x); 
	if(ch[x][1]&&S[ch[x][1]]>=k&&s[ch[x][1]]<=k)return find(ch[x][1],k);
	if(w[x]==k)return x;
	return find(ch[x][0],k);
}
bool zx(int x,int y){
	return check(in[x],in[y])&&check(out[y],out[x]);
}
int main(){
	n=read(); m=read(); tot=1;
	for(int i=1;i<=n;i++){
		v[i].resize(read()); for(auto &j:v[i])j=read();
	}
	dep[1]=1;
	dfs(1); tot++;
	s[1]=w[1]=s[tot]=w[tot]=1e9; S[1]=W[1]=S[tot]=W[tot]=-1e9;
	for(int i=tot;i>1;i--)insert(i,i-1); 
	while(m--){
		int op=read();
		if(op==1){
			int u=read(),v=read(),A=getdep(u),B=getdep(v),k=s[get(in[u],in[v])]; 
			writeln(A+B-2*(k-(!zx(u,v)&&!zx(v,u))));
		}else if(op==2){
			int x=read(),jj=getdep(x); splay(in[x],0); int y=tong[find(ch[rt][0],jj-read())]; 
			int delta=getdep(y)+1-getdep(x),t=get(in[x],out[x]);
			ch[fa[t]][get(t)]=0; Update(fa[t]); fa[t]=0;
			cao(t,delta); insert(out[y],t); 
		}else if(op==3) {int t=find(rt,read()+1); splay(t,0); writeln(tong[t]);}
	}
}