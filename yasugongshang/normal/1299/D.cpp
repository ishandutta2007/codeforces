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
const int N=100005,ZT=500,K=5,mod=1e9+7;

struct data{
	int a[K];
	bool ins(int x){
		Rep(i,K-1,0)if(x>>i&1){
			if(a[i]){
				x^=a[i];
			}else {
				For(j,0,i-1)if(x>>j&1)x^=a[j];
				a[i]=x;
				For(j,i+1,K-1)if(a[j]>>i&1)a[j]^=x;
				return 1;
			}
		}
		return 0;
	}
	int& operator [](int x){
		return a[x];
	}
}A[ZT],ffff,qj;
bool operator <(data a, data b){
	For(i,0,K-1)if(a[i]!=b[i])return a[i]<b[i];
	return 0;
}
map<data,int> M;
vector<pair<int,int> > v[N];
bool vis[N],bj[N];
int dis[N],alb[N],fa[N],Q,QJ,QQ;
void dfs(int p){
	vis[p]=1;//cout<<p<<endl;
	for(auto i:v[p])if(i.fi!=1){
		if(!vis[i.fi]){
			dis[i.fi]=dis[p]^i.se; 
			fa[i.fi]=p; dfs(i.fi);
		}else{
			if(bj[p]&&bj[i.fi]){Q=1; QQ=alb[p]^alb[i.fi]^i.se;}
			else if(i.fi!=fa[p]&&i.fi<p){
				QJ*=qj.ins(i.se^dis[p]^dis[i.fi]);
				//cout<<i.se<<" fa[p]:"<<fa[p]<<" "<<p<<" "<<i.fi<<" fjsiaihnf "<<dis[p]<<" "<<dis[i.fi]<<endl;
			}
		}	
	}
}
int dq,gg[ZT][ZT],zy[ZT][ZT];
ll ans,f[ZT],g[ZT];
inline void add(ll &a,ll b){
	a=(a+b)%mod;
}
void dfs(data a){
	if(!M.count(a)){
		M[a]=++dq; A[dq]=a;
	}else return;
	For(j,0,(1<<K)-1){
		data b=a; b.ins(j);
		dfs(b);
	}
}
int main(){
	dfs(ffff);
	For(i,1,dq)For(j,1,dq){
		data a=A[i];
		gg[i][j]=1;
		For(o,0,K-1)if(A[j][o])gg[i][j]&=a.ins(A[j][o]);
		zy[i][j]=M[a];
	}
	int n=read(),m=read();
	For(i,1,m){
		int a=read(),b=read(),w=read();
		v[a].pb(mp(b,w));
		v[b].pb(mp(a,w));
	}
	for(auto i:v[1]){
		bj[i.fi]=1; alb[i.fi]=i.se;
	}
	vis[1]=1; f[1]=1;
	for(auto i:v[1])if(!vis[i.fi]){
		Q=0; QJ=1;
		mem(qj.a); 
		dfs(i.fi); if(!QJ)continue;
		memcpy(g,f,sizeof(f));
		//For(i,0,K-1)wri(qj.a[i]); puts("zhu");
		if(Q){
			int x=M[qj];
			QJ*=qj.ins(QQ);
			int y=M[qj];
			For(j,1,dq){
				if(gg[j][x])add(g[zy[j][x]],f[j]*2);
				if(gg[j][y])add(g[zy[j][y]],f[j]*QJ);
			}
		}else{
			int x=M[qj];
			For(j,1,dq)if(gg[j][x])add(g[zy[j][x]],f[j]);
		}
		swap(f,g);
	}
	
	For(i,1,dq)add(ans,f[i]);
	cout<<ans<<endl;
}
/*
4 3
1 2 1
1 3 1
2 3 1

*/