#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((ll)(x)*(x))
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
    for (; !isdigit(ch); ch = gc())    if (ch == '-')    positive = 0;
    for (; isdigit(ch); ch = gc())    x = x * 10 + ch - '0';
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
const int N=100005,inf=1e9,K=17,B=50;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
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
map<int,int> M;
int n,w,q,dq[N],a[N],vis[N],k[N],kk[N],f[N][K],g[N][K],mx[N][B+1],mn[N][B+1];
vector<int> v[N];
int cal(int x){
	int ans=0;
	for(int i=1;i<=n;){
		ans+=T.query(i)-1;
		i=T.findroot(i);
		if(i>n)return ans;
		int dm=0,dn=inf;
		for(int j=K-1;j>=0;j--)if(i+(1<<j)<=n+1&&max(dm,f[i][j])-min(dn,g[i][j])<=x){
			dm=max(dm,f[i][j]); dn=min(dn,g[i][j]); i+=1<<j;
		}
		ans++; 
	} 
	return ans;
}
int main(){
    n=read(); w=read(); q=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=q;i++)kk[i]=k[i]=w-read();
    sort(&kk[1],&kk[q+1]);
    for(int i=1;i<=n;i++){
    	mx[i][0]=mn[i][0]=f[i][0]=g[i][0]=a[i];
    	for(int j=1;i+j<=n&&j<=B;j++){
    		mx[i][j]=max(mx[i][j-1],a[i+j]); mn[i][j]=min(mn[i][j-1],a[i+j]);
    		int pos=lower_bound(&kk[1],&kk[q+1],mx[i][j]-mn[i][j])-kk;
    		v[pos].push_back(i);
    	}
    }
  	for(int i=1;i<=n+1;i++)T.sum[i]=1;
    for(int i=1;i<=n;i++)T.link(i,i+1);
    for(int j=1;j<K;j++)for(int i=1;i+(1<<j)-1<=n;i++){
    	f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]); g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
    }
    for(int i=1;i<=q;i++){
    	for(auto j:v[i])if(!vis[j]){
    		vis[j]=1;
    		T.cut(j,j+dq[j]+1);
    		while(dq[j]<B&&j+dq[j]<n&&mx[j][dq[j]+1]-mn[j][dq[j]+1]<=kk[i])dq[j]++;
    		if(dq[j]!=B)T.link(j,j+dq[j]+1);
    	}
    	//for(int j=1;j<=n;j++)cout<<dq[j]<<endl;
    	for(auto j:v[i])vis[j]=0;
    	//puts("wzp"); for(int j=1;j<=n;j++)cout<<T.getfa(j)<<endl;
    	M[kk[i]]=cal(kk[i]);
    }
    for(int i=1;i<=q;i++)writeln(M[k[i]]-1);
}