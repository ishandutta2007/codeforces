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
#define SZ(x) ((int)(x.size()))
#define re resize
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int M=1<<10|2,N=10005;
int n,m,k,q,id[10],ycl[M],sum[M],s[N],t[N],w[N],dep[N],cur[N],pre[N];
struct graph{
	const static int N=10005,M=20005,inf=1e5;
	int ans,ne,son[N];
	struct Edge{
		int ed,di,nxt;
	}e[M];
	graph(){
		ans=0; ne=1; mem(son);
	}
	void ae(int a,int b,int c){
		e[++ne].nxt=son[a]; son[a]=ne; e[ne].ed=b; e[ne].di=c;
	}
	void ins(int a,int b,int c){
		ae(a,b,c); ae(b,a,0);
	}
	int bfs(int s,int t){
		For(i,1,N-1){
			dep[i]=inf; cur[i]=son[i];
		}
		dep[s]=0; 
		static int q[N];int tot=0; q[0]=s;
		For(i,0,tot){
			int p=q[i]; 
			for(int i=son[p];i;i=e[i].nxt)if(e[i^1].di&&dep[e[i].ed]==inf){
				dep[e[i].ed]=dep[p]+1; pre[e[i].ed]=i^1; q[++tot]=e[i].ed;
			}
		}
		return dep[t]<inf;
	}
	int dfs(int s,int limit){
		if(!limit||s==n)return limit;
		int ans=0;
		for(int &i=cur[s];i;i=e[i].nxt)if(e[i].di&&dep[e[i].ed]==dep[s]-1){
			int zs=dfs(e[i].ed,min(limit,e[i].di)); 
			limit-=zs; e[i].di-=zs; e[i^1].di+=zs; ans+=zs; 
			if(!limit)break;
		}
		if(!ans)dep[s]=-1;
		return ans;
	}
	void dinic(int s,int t){
		while(bfs(t,s))ans+=dfs(s,inf);
	}
	void alb(int s,int t){
		while(bfs(t,s)){
			for(int i=s;i!=t;i=e[pre[i]].ed){
				e[pre[i]].di--; e[pre[i]^1].di++; 
			}
			ans++;
		}
	}
};
void dfs(int p,int zt,graph &G){
	if(p==k){
		ycl[zt]=G.ans; return;
	}
	
	dfs(p+1,zt|(1<<p),G);
	graph H=G; 
	H.ins(s[p],t[p],25);
	H.alb(1,n);
	dfs(p+1,zt,H);
}
int main(){
	srand(19260817);
	n=read(); m=read(); k=read(); q=read();
	For(i,0,k-1) id[i]=i;
	random_shuffle(id,id+k);
	For(i,0,k-1){
		s[id[i]]=read(); t[id[i]]=read(); w[id[i]]=read();
	}
	For(i,k,m-1){
		s[i]=read(); t[i]=read(); w[i]=read();
	}
	graph G; 
	For(i,k,m-1){
		int id=rand()%(i-k+1)+k;
		swap(s[id],s[i]); swap(t[id],t[i]); swap(w[id],w[i]);
	}
	For(i,k,m-1)G.ins(s[i],t[i],w[i]);
	G.dinic(1,n); dfs(0,0,G);
	//cout<<ycl[0]<<" "<<ycl[1]<<endl;
	while(q--){
		int ans=ycl[0];
		For(i,0,k-1)w[id[i]]=read();
		For(i,1,(1<<k)-1){
			
			For(j,0,k-1)if(i>>j&1){sum[i]=sum[i^(1<<j)]+w[j]; break;}
			ans=min(ans,ycl[i]+sum[i]);
		}
		writeln(ans);
	}
}