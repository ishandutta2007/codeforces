#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
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
const int N=100005;
pair<ll,ll> q[N*20];
int tot,FA[N];
ll dep[N];
vector<pair<int,int> > e[N];
struct link_cut_tree{
    int ch[N][2],fa[N],rev[N],lst[N],lzy[N];
    inline int get(int x){return ch[fa[x]][1]==x;}
    inline int isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
    inline void rever(int x){rev[x]^=1; swap(ch[x][0],ch[x][1]);}
    inline void update(int x){}
    inline void cao(int x,int y){
    	lst[x]=y; lzy[x]=y;
	}
    inline void pushdown(int x){
        if(rev[x]){
            if(ch[x][0])rever(ch[x][0]);
            if(ch[x][1])rever(ch[x][1]);
            rev[x]=0;
        }
        if(lzy[x]){
        	if(ch[x][0])cao(ch[x][0],lzy[x]);
        	if(ch[x][1])cao(ch[x][1],lzy[x]);
        	lzy[x]=0;
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
    void access(int x,int jb,int t){
    	int y=0;
        for(;x;y=x,x=fa[x]){
    	//cout<<isroot(3)<<" "<<ch[1][0]<<" "<<fa[3]<<" "<<ch[1][1]<<" "<<fa[2]<<endl;
            splay(x); 
            ch[x][1]=y; 
			if(y||jb){
        	//cout<<x<<" "<<y<<" "<<lst[x]+dep[x]+1<<" "<<t+dep[x]<<" "<<lst[x]<<endl;
				q[++tot]=mp(lst[x]?lst[x]+dep[x]+1:1,t+dep[x]); 
			}
			update(x);
        }
        cao(y,t);
    }
    void solve(int x,int t){
    	if(x==1)return;
    	splay(x);
    	access(FA[x],ch[x][0]==0,t);
    	splay(FA[x]);
		ch[FA[x]][1]=x;
	}
}T;
void dfs(int p){
	for(auto i:e[p]){
		dep[i.fi]=dep[p]+i.se;
		dfs(i.fi);
	}
}
void GG(ll ans){
	int sum=0;
	For(i,1,tot)if(q[i].se<ans)sum++; if(ans<0)sum=tot;
	cout<<ans<<" "<<sum<<endl;
	exit(0);
}
int main(){
	int n=read(),m=read();
	For(i,1,n-1){
		int s=read(),t=read(),d=read();
		e[s].pb(mp(t,d)); T.ch[s][1]=t; FA[t]=T.fa[t]=s;
	}
	dfs(1);
	For(i,1,m){
		int x=read(),t=read();
		T.solve(x,t);
	}
	sort(q+1,q+tot+1);
	priority_queue<ll,vector<ll>,greater<ll> > Q;
	//For(i,1,tot) cout<<q[i].fi<<" fjzzq "<<q[i].se<<endl;
	For(i,1,tot){
		for(ll j=q[i-1].fi;j<q[i].fi&&Q.size();j++){ if(Q.top()<j)GG(Q.top()); Q.pop(); }
		Q.push(q[i].se);
	}
	for(ll j=q[tot].fi;Q.size();j++){ if(Q.top()<j)GG(Q.top());Q.pop();}
	GG(-1);
}