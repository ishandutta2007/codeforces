#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=10000,M=400005;
int n,q[N],nedge=1,son[N],nextt[M],ed[M];
int cost[M],dist[N],di[M];
bool vis[N];
int last[N],que[N],laedge[N];
int a[4405],b[4405];
ll g[N],f[N],jb[N],jj[N];
bool spfa(int s,int t,int n){
    for (int i=1;i<=n;i++) {dist[i]=inf;last[i]=laedge[i]=vis[i]=que[i-1]=0;}
    int tot=1,l=0,r=0; que[0]=s; vis[s]=true; dist[s]=0;
    while (tot) {
        int k=que[l];
        vis[k]=false;
        if (++l==n) l=0;
        tot--; 
        for(int i=son[k];i;i=nextt[i]){
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
	int sum=0,cost=0;
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
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c; cost[nedge]=d;
}
inline void ins(int a,int b,int c,int d){
    aedge(a,b,c,d); aedge(b,a,0,-d);
}
bool cmp(int x,int y){
	return mp(b[x],-a[x])<mp(b[y],-a[y]);
}
bool cmg(int x,int y){
	return g[x]<g[y];
}
bool check(ll x){
	ll mx=0;
	*jb=*jj=0;
	For(i,1,n*2){
		mx=max(mx,x*a[q[i]]+b[q[i]]);
		if(q[i]<=n){
			jb[++*jb]=mx;
		}else jj[++*jj]=x*a[q[i]]+b[q[i]];
	}
	sort(jj+1,jj+n+1);
	For(i,1,n)if(jb[i]<jj[i])return 0;
	return 1;
}
void solve(ll x){
	int s=4*n+1,t=s+1;
	ll mx=0;
	For(i,1,n*2){
		mx=max(mx,x*a[q[i]]+b[q[i]]);
		if(q[i]<=n){
			f[q[i]]=mx;
		}
	}
	For(i,n+1,2*n)g[q[i]=i]=b[i];
	sort(q+n+1,q+2*n+1,cmg);
	For(i,n+1,2*n){
		ins(q[i]+n,q[i],1,0);
		if(i>n+1)ins(q[i]+n,q[i-1]+n,inf,0);
		ins(i,t,1,0);
	}
	For(i,1,n){
		Rep(j,2*n,n+1)if(g[q[j]]<=b[i]){
			ins(i,q[j]+n,1,0); break;
		}
		ins(s,i,1,0);
	}
	For(i,n+1,2*n)g[q[i]=i]=a[i]*x+b[i];
	sort(q+n+1,q+2*n+1,cmg);
	For(i,n+1,2*n){
		ins(q[i]+2*n,q[i],1,0);
		if(i>n+1)ins(q[i]+2*n,q[i-1]+2*n,inf,0);
	}
	For(i,1,n){
		Rep(j,2*n,n+1)if(g[q[j]]<=f[i]){
			//cout<<i<<" "<<q[j]<<endl;
			ins(i,q[j]+2*n,1,1); break;
		}
		Rep(j,2*n,n+1)if(g[q[j]]<=x*a[i]+b[i]){
			//cout<<i<<" "<<j-n<<" "<<q[j]-n<<endl;
			ins(i,q[j]+2*n,1,0); break;
		}
	}
	writeln(costflow(s,t,t)+n);
}
int main(){
	n=read();
	For(i,1,n*2){
		a[i]=read(); b[i]=read(); q[i]=i;
	}
	sort(&q[1],&q[2*n+1],cmp);
	int l=0,r=inf+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid; else l=mid+1;
	}
	if(r>inf)puts("-1");
	else{
		wri(l); 
		solve(l);
	}
}