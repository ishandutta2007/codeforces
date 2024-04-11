#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
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
const int N=205,M=100005,inf=1e9;
int di[M],nxt[M],ed[M];
int n,m,son[N],nedge,cur[N],deep[N];
inline void aedge(int a,int b,int c){
    nxt[++nedge]=son[a]; 
    son[a]=nedge;
    ed[nedge]=b;
    di[nedge]=c;
}
inline void ins(int a,int b,int c){
    aedge(a,b,c); aedge(b,a,0);
}
inline bool bfs(int s,int t){
    for(int i=0;i<N;i++)deep[i]=inf;
    for(int i=0;i<N;i++)cur[i]=son[i];
    deep[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int tmp=son[now];tmp;tmp=nxt[tmp])
            if(deep[ed[tmp]]>=inf&&di[tmp]){deep[ed[tmp]]=deep[now]+1,q.push(ed[tmp]);}
    }
    return deep[t]<inf;
}
int dfs(int now,int t,int limit){
    if(!limit||now==t) return limit;
    int flow=0,f;
    for(int tmp=cur[now];tmp;tmp=nxt[tmp]){
        cur[now]=tmp;
        if(deep[ed[tmp]]==deep[now]+1&&(f=dfs(ed[tmp],t,min(limit,di[tmp])))){
            flow+=f; limit-=f; di[tmp]-=f; di[((tmp-1)^1)+1]+=f; if(!limit)break;
        }
    }
    return flow;
}
inline int dinic(int s,int t){
    int ans=0;
    while(bfs(s,t))ans+=dfs(s,t,inf);
    return ans;
}
int xa[N],xb[N],ya[N],yb[N],qx[N],qy[N];
bool e[N][N];
int main(){
	int n=read(),m=read();
	For(i,1,m){
		xa[i]=read(); ya[i]=read();
		xb[i]=read()+1; yb[i]=read()+1;
		qx[++*qx]=xa[i]; qx[++*qx]=xb[i];
		qy[++*qy]=ya[i]; qy[++*qy]=yb[i];
	}
	sort(&qx[1],&qx[*qx+1]);
	sort(&qy[1],&qy[*qy+1]);
	*qx=unique(&qx[1],&qx[*qx+1])-qx-1;
	*qy=unique(&qy[1],&qy[*qy+1])-qy-1;
	For(i,1,m){
		xa[i]=lower_bound(&qx[1],&qx[*qx+1],xa[i])-qx;
		xb[i]=lower_bound(&qx[1],&qx[*qx+1],xb[i])-qx;
		ya[i]=lower_bound(&qy[1],&qy[*qy+1],ya[i])-qy;
		yb[i]=lower_bound(&qy[1],&qy[*qy+1],yb[i])-qy;
		For(j,xa[i],xb[i]-1){
			For(k,ya[i],yb[i]-1)e[j][k]=1;
		}
	}
	int s=*qx+*qy+1,t=s+1;
	For(i,1,*qx-1)For(j,1,*qy-1)if(e[i][j])ins(i,j+*qx,inf);
	For(i,1,*qx-1)ins(s,i,qx[i+1]-qx[i]);
	For(i,1,*qy-1)ins(i+*qx,t,qy[i+1]-qy[i]);
	cout<<dinic(s,t)<<endl;
}