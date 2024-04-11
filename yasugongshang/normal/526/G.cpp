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
const int N=100005,inf=1e9,K=18;
int MX,rt,tot,ne,sss,lastans;
int fa[N],sum[N],dp[N][K],mn[N],dep[N],wson[N],son[N],nxt[N<<1],ed[N<<1],di[N<<1];
PI mx[N],q[N];
void ae(int a,int b,int c){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b; di[ne]=c;
}
void Dfs(int p,int dep){
	if(dep>MX){MX=dep; rt=p;}
	for(int i=son[p];i;i=nxt[i])if(ed[i]!=fa[p]){
		fa[ed[i]]=p;
		Dfs(ed[i],dep+di[i]);
	}
}
void dfs(int p){
	mx[p]=mp(dep[p],p); //cout<<p<< " "<<ed[son[p]]<< " "<<fa[p]<<endl;
	for(int i=son[p];i;i=nxt[i])if(ed[i]!=fa[p]){
		dep[ed[i]]=dep[p]+di[i]; fa[ed[i]]=p; dfs(ed[i]);
		if(mx[ed[i]]>mx[p]){
			wson[p]=ed[i]; mx[p]=mx[ed[i]];
		}
	}
	for(int i=son[p];i;i=nxt[i])if(ed[i]!=fa[p]&&ed[i]!=wson[p]){
		q[++tot]=mx[ed[i]]; q[tot].fi-=dep[p];
	}
}
void ddd(int p){
	if(!mn[p])mn[p]=inf;
	for(int i=son[p];i;i=nxt[i])if(ed[i]!=fa[p]){
		ddd(ed[i]);
		mn[p]=min(mn[ed[i]],mn[p]);
	}
}
int ask(int x,int y){
	Rep(i,K-1,0)if(dp[x][i]&&mn[dp[x][i]]>y)x=dp[x][i];
	return dp[x][0];
}
int main(){
	int n=read(),Q=read();
	For(i,1,n-1){
		int s=read(),t=read(),l=read();
		ae(s,t,l); ae(t,s,l); sss+=l;
	}
	Dfs(1,0); //cout<<son[rt]<<" "<<ed[10]<<endl;
	fa[rt]=0; dfs(rt); q[++tot]=mx[rt];
	sort(q+1,q+tot+1); reverse(q+1,q+tot+1);
	For(i,1,tot)mn[q[i].se]=i;  
	ddd(rt);
	For(i,1,tot)sum[i]=sum[i-1]+q[i].fi;
	For(i,1,n)dp[i][0]=fa[i]; 
	For(i,1,K-1)For(j,1,n)dp[j][i]=dp[dp[j][i-1]][i-1]; //cout<<rt<<" "<<sum[3]<<endl;
	while(Q--){
		int x=(read()+lastans-1)%n+1,y=(read()+lastans-1)%n+1; 
		if(tot<=2*y-1){writeln(lastans=sss); continue;}
		if(mn[x]<2*y)writeln(lastans=sum[2*y-1]);
		else {
			int t=ask(x,2*y-1);//cout<<rt<<" "<<x<<" "<<y<<" "<<t<<" "<<mn[x]<<endl;
			writeln(lastans=max(sum[2*y-1]-2*dep[t]+mx[x].fi,max(sum[2*y-1]+mx[x].fi-mx[t].fi,sum[2*y-2]+mx[x].fi-dep[t])));
		}
		//if(lastans==37)cout<<x<<" fjjzq "<<y<<endl;
	}
}
/*
11 1
2 1 6
3 1 10
4 3 8
5 2 1
6 5 7
7 5 4
8 2 7
9 4 1
10 4 3
11 2 2
9 2

*/