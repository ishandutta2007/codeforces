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
const int inf=1e9;
const int N=1600,M=100005;
int nedge=1,son[N],nxt[M],ed[M];
int cost[M],dist[N],di[M];
bool vis[N];
int tot,last[N],que[N],laedge[N];
int a[55][55],ans[55][55];
bool spfa(int s,int t,int n){
    for (int i=1;i<=n;i++) {dist[i]=inf;last[i]=laedge[i]=vis[i]=que[i-1]=0;}
    int tot=1,l=0,r=0; que[0]=s; vis[s]=true; dist[s]=0;
    while (tot) {
        int k=que[l];
        vis[k]=false;
        if (++l==n) l=0;
        tot--; 
        for(int i=son[k];i;i=nxt[i]){
            if(di[i]>0&&dist[ed[i]]>dist[k]+cost[i]){
                dist[ed[i]]=dist[k]+cost[i]; laedge[ed[i]]=i; last[ed[i]]=k;
                if(vis[ed[i]]==0) {
                    if(++r==n)r=0;
                    que[r]=ed[i]; tot++; vis[ed[i]]=true;
                }
            }
        }
    }
    return last[t]>0;
}
int costflow(int s,int t,int n){
	int sum=0; int cost=0;
    while(spfa(s,t,n)){
        int mmin=inf; 
        for(int i=t;last[i];i=last[i]){mmin=min(mmin,di[laedge[i]]);}
        sum+=mmin;
        cost+=dist[t]*mmin;
        for(int i=t;last[i];i=last[i]){
            di[laedge[i]]-=mmin;
            di[laedge[i]^1]+=mmin;
        }
    }
    return cost;
}
inline void aedge(int a,int b,int c,int d){
    nxt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c; cost[nedge]=d;
}
inline void ins(int a,int b,int c,int d){
    aedge(a,b,c,d); aedge(b,a,0,-d);
}
int main(){
	int n=read(),m=read();
	memset(a,-1,sizeof(a));
	For(i,1,m){
		int s=read(),t=read();
		a[s][t]=1; a[t][s]=0;
	}
	int s=n+1,t=n+2,tot=n+2;
	For(i,1,n)For(j,i+1,n){
		tot++;
		if(a[i][j]!=1)ins(tot,j,1,0);
		if(a[i][j]!=0)ins(tot,i,1,0);
		ins(s,tot,1,0);
	}
	For(i,1,n)For(j,1,n-1)ins(i,t,1,j*(j-1)/2-(j-1)*(j-2)/2);
	costflow(s,t,tot);
	tot=n+2;
	For(i,1,n)For(j,i+1,n){
		tot++;
		for(int k=son[tot];k;k=nxt[k])if(ed[k]<=n&&di[k]==0){
			ans[i][j]=ed[k]==i;
			ans[j][i]=ans[i][j]^1;
		}
	}
	For(i,1,n){
		For(j,1,n)write(ans[i][j]); puts("");
	}
}