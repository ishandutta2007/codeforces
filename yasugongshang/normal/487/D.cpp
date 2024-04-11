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
const int N=1300005;
char ch[100005][15];
struct link_cut_tree{
    int ch[N][2],fa[N],rev[N],sum[N],w[N];
    inline int get(int x){return ch[fa[x]][1]==x;}
    inline int isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
    inline void rever(int x){rev[x]^=1; swap(ch[x][0],ch[x][1]);}
    inline void update(int x){sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+1;}
    inline void pushdown(int x){
        if(rev[x]){
            if(ch[x][0])rever(ch[x][0]);
            if(ch[x][1])rever(ch[x][1]);
            rev[x]=0;
        }
    }
    inline void push(int x){if(!isroot(x))push(fa[x]); pushdown(x);}
    inline void rotate(int x){
        int f=fa[x],g=fa[f],c=get(x);
        if(!isroot(f))ch[g][get(f)]=x; fa[x]=g;
        ch[f][c]=ch[x][c^1]; fa[ch[f][c]]=f;
        ch[x][c^1]=f; fa[f]=x;
        update(f); update(x);
    }
    inline void splay(int x){
        for(push(x);!isroot(x);rotate(x))
            if(!isroot(fa[x]))rotate(get(fa[x])==get(x)?fa[x]:x);
    }
    void access(int x){
        for(int y=0;x;y=x,x=fa[x]){
            splay(x); ch[x][1]=y; update(x);
        }
    }
    void makeroot(int x){
        access(x); splay(x); rever(x);
    }
    int findroot(int x){
        access(x); splay(x);
        while(ch[x][0])x=ch[x][0];
        return x;
    }
    void link(int x,int y){
        makeroot(x); fa[x]=y;
    }
    void split(int x,int y){
        makeroot(x); access(y); splay(y);
    }
    void cut(int x,int y){
    	int t=findroot(x);
        rever(x); access(y); splay(y);
        fa[x]=ch[y][0]=0; update(y);
        makeroot(t);
    }
    int getfa(int x){
    	access(x); splay(x);
    	x=ch[x][0]; pushdown(x);
    	while(ch[x][1]){pushdown(x); x=ch[x][1];}
    	return x;
    }
    void change(int x,int y){
        access(x); splay(x);
        w[x]=y; update(x);
    }
    int query(int x){
    	access(x); splay(x); return sum[x];
	}
}T;
int n,m,q,v[N];
char Ch[5];
#define zb(x,y) (x)*(m+2)+(y)
void alb(int x,int y){
	int jb;
	if(ch[x][y]=='<')jb=zb(x,y-1);
	else if(ch[x][y]=='>')jb=zb(x,y+1);
	else if(ch[x][y]=='^')jb=zb(x-1,y);
	else jb=zb(x+1,y);
	if(T.findroot(zb(x,y))!=T.findroot(jb)){v[zb(x,y)]=1; T.link(zb(x,y),jb);} else v[zb(x,y)]=0;
}
int fa[N];
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
void Alb(int x,int y){
	int jb;
	if(ch[x][y]=='<')jb=zb(x,y-1);
	else if(ch[x][y]=='>')jb=zb(x,y+1);
	else if(ch[x][y]=='^')jb=zb(x-1,y);
	else jb=zb(x+1,y);
	if(gf(zb(x,y))!=gf(jb)){fa[zb(x,y)]=jb; v[zb(x,y)]=1; T.link(zb(x,y),jb);} else v[zb(x,y)]=0;
}
void lie(int x,int y){
	if(!v[zb(x,y)])return;
	int jb;
	if(ch[x][y]=='<')jb=zb(x,y-1);
	else if(ch[x][y]=='>')jb=zb(x,y+1);
	else if(ch[x][y]=='^')jb=zb(x-1,y);
	else jb=zb(x+1,y);
	T.cut(zb(x,y),jb);
	if((ch[x][y]=='<'&&ch[x][y-1]=='>')||(ch[x][y]=='>'&&ch[x][y+1]=='<'))alb(x,ch[x][y]=='<'?y-1:y+1);
}
int main(){
	n=read(); m=read(); q=read();
	for(int i=0;i<N;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		for(int j=1;j<=m;j++)Alb(i,j);
	}
	while(q--){
		scanf("%s",Ch);
		if(Ch[0]=='C'){
			int x=read(),y=read();
			lie(x,y);
			ch[x][y]=getchar();
			alb(x,y);
		}else{
			int x=read(),y=read();
			int t=T.findroot(zb(x,y));
			int xx=t/(m+2),yy=t%(m+2);
			if(xx==0||yy==0||xx>n||yy>m){
				write(xx); putchar(' '); writeln(yy);
			}else puts("-1 -1");
		}
	}
}