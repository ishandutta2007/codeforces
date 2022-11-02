#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
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
const int N=400005;
#define lowbit(i) i&-i
int dq,p[N],to[N],c[N],color[N];
void change(int pos,int de){
	for(int i=pos;i<N;i+=lowbit(i))c[i]+=de;
}
int get(int pos){
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))ans+=c[i];
	return ans;
}
struct link_gay_tree{
	int fa[N],ch[N][2],rev[N],sz[N];
	inline int get(int x){return ch[fa[x]][1]==x;}
	inline int isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
	inline void rever(int x){rev[x]^=1; swap(ch[x][0],ch[x][1]);}
	inline void update(int x){sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;}
	inline void mc(int x,int y){color[x]=y;}
	inline void pushdown(int x){
		if(rev[x]){
			rever(ch[x][0]); rever(ch[x][1]); rev[x]=0;
		}
		if(color[x]){
			mc(ch[x][0],color[x]); mc(ch[x][1],color[x]);
		}
	}
	inline void push(int x){if(!isroot(x))push(fa[x]);pushdown(x);}
	inline void rotate(int x){
		int f=fa[x],g=fa[f],c=get(x);
        if(!isroot(f))ch[g][get(f)]=x; fa[x]=g;
        ch[f][c]=ch[x][c^1]; fa[ch[f][c]]=f;
        ch[x][c^1]=f; fa[f]=x;
        update(f); update(x);
	}
	void splay(int x){
		for(push(x);!isroot(x);rotate(x)){
			if(!isroot(fa[x]))rotate(get(x)==get(fa[x])?fa[x]:x);
		}
	}
	void access(int x){
		for(int y=0;x;y=x,x=fa[x]){
			splay(x); if(color[x])change(color[x],-sz[ch[x][0]]-1); 
			color[x]=dq; change(dq,sz[ch[x][0]]+1);
			ch[x][1]=y; update(x);
		}
	}
	void makeroot(int x){
		access(x); splay(x); rever(x);
	}
	int gg(int x){
		if(isroot(x))return 1;
		while(!isroot(fa[x]))x=fa[x];
		return sz[x]+1;
	}
}T;
vector<int> v[N];
char op[10];
void dfs(int p,int fa){
	for(auto i:v[p])if(i!=fa){
		T.fa[i]=p;
		dfs(i,p);
	}
}
int gg(int p){
	T.splay(p);
	return get(color[p]-1)+T.gg(to[color[p]-1]);
}
int main(){
	int n=read(),m=read(); dq=1;
	for(int i=1;i<=n;i++){to[p[i]=i]=i; T.sz[i]=1;}
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs(1,0);
	for(int i=2;i<=n;i++){
		dq++; T.makeroot(to[i]);
	}
	while(m--){
		scanf("%s",op);
		if(op[0]=='u'){
			int x=read(); dq++; to[dq]=x;
			T.makeroot(x);
		}else if(op[0]=='w'){
			int x=read();
			writeln(gg(x));
		}else{
			int x=read(),y=read();
			writeln((gg(x)<gg(y))?x:y);
		}
	}
}