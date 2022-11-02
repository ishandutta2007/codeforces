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
const int N=805,inf=1e9,M=22;
int n,m,lst[N],v[N],u[N],zb[M][M];
struct graph1{
	int fa[N/2];
	void init(){
		For(i,0,n-1){
			fa[i]=i; 
		}
	}
	inline int gf(int x){
		return fa[x]==x?x:fa[x]=gf(fa[x]);
	}
	void ins(int s,int t){
		s=gf(s); t=gf(t);
		fa[s]=t;
	}
	bool check(int s,int t){
		s=gf(s); t=gf(t);
		return s!=t;
	}
}G1,G3;
struct graph2{
	int d[N/2];
	void init(){
		For(i,0,n-1)d[i]=0;
	}
	void ins(int s,int t){
		d[s]++;
	}
	bool check(int s,int t){
		return d[s]<2;
	}
}G2;
int used[N],dis[N],vis[N];
vector<int> e[N];
char ans[M*2][M*2],ch[M][M];
int spfa(int s,int t){
	For(i,1,t){dis[i]=inf; vis[i]=0;}
	queue<int> q;
	q.push(s); dis[s]=0;
	while(q.size()){
		int t=q.front(); q.pop(); vis[t]=0;
		for(auto i:e[t]){
			int di=dis[t]+1;
			if(dis[i]==inf){//cout<<i<<" fj  "<<t<<endl;
				lst[i]=t; dis[i]=di; if(!vis[i]){vis[i]=1; q.push(i);}
			}
		}
	}
	return dis[t];
}
int solve(){
	int s=m+1,t=s+1;
	For(i,1,t)e[i].clear();
	For(i,1,m)if(used[i]){
		G1.init(); G2.init();
		For(j,1,m)if(used[j]&&j!=i){
			G1.ins(u[j],v[j]);
			G2.ins(u[j],v[j]);
		}
		For(j,1,m)if(!used[j]){
			if(G1.check(u[j],v[j]))e[i].pb(j);
			if(G2.check(u[j],v[j]))e[j].pb(i);
		}
	}
	G1.init(); G2.init();
	For(i,1,m)if(used[i]){
		G1.ins(u[i],v[i]);
		G2.ins(u[i],v[i]);
	}
	For(i,1,m)if(!used[i]){
		if(G1.check(u[i],v[i]))e[s].pb(i);
		if(G2.check(u[i],v[i]))e[i].pb(t);
	}
	int zs=spfa(s,t);
	if(zs<inf){
		for(int i=lst[t];i!=s;i=lst[i]){ used[i]^=1;}
		return 1;
	}
	return 0;
}
int main(){
	int T=read();
	while(T--){
		int r=read(),c=read();n=0; m=0;
		mem(used);
		For(i,0,r-1)scanf("%s",ch[i]);
		For(i,0,r-1)For(j,0,c-1)zb[i][j]=n++;
		ch[0][0]='X';
		int lim=0;
		For(i,0,r-1)For(j,0,c-1)if(ch[i][j]=='O'&&(i+j)%2==0)lim++;
		For(i,0,r-1){
			For(j,0,c-2)if(ch[i][j]=='O'&&ch[i][j+1]=='O'){
				m++;
				u[m]=zb[i][j]; v[m]=zb[i][j+1]; if((i+j)&1)swap(u[m],v[m]);
			}
			if(i<r-1)For(j,0,c-1)if(ch[i][j]=='O'&&ch[i+1][j]=='O'){
				m++;
				u[m]=zb[i][j]; v[m]=zb[i+1][j]; if((i+j)&1)swap(u[m],v[m]);
			}
		}
		lim*=2; 
		//For(i,1,m)cout<<u[i]<<" "<<v[i]<<endl;
		while(solve())lim--;
		if(lim){puts("NO"); continue;}
		ch[0][0]='O';
		if(ch[0][1]=='O'){
			m++;
			u[m]=zb[0][0]; v[m]=zb[0][1];
		}
		if(ch[1][0]=='O'){
			m++;
			u[m]=zb[0][0]; v[m]=zb[1][0];
		}
		For(i,0,n-1)G3.fa[i]=i;
		For(i,1,m)if(used[i])G3.ins(u[i],v[i]);
		For(i,1,m)if(!used[i]){
			if(G3.check(u[i],v[i])){G3.ins(u[i],v[i]); used[i]=1;}
		}
		For(i,0,2*r-2){
			For(j,0,2*c-2){ans[i][j]=' '; if(i%2==0&&j%2==0)ans[i][j]=ch[i/2][j/2];}
			ans[i][2*c-1]=0;
		}
		For(i,1,m)if(used[i]){
			if(u[i]>v[i])swap(u[i],v[i]);
			int x=u[i]/c,y=u[i]%c; //cout<<x<<" "<<y<<" "<<x*2<<" "<<y*2+1<<endl;
			if(v[i]==u[i]+1)ans[x*2][y*2+1]='O'; 
			else ans[x*2+1][y*2]='O';
		}
		puts("YES");
		For(i,0,2*r-2)puts(ans[i]);
	}
}
/*
1
4 4
OOOX
XOOX
OOXO
OOOO

*/