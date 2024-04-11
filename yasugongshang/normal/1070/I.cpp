#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=10005,M=10005,oo=1e9;
struct edge{
	int di,nextt,ed;
}e[M];
int son[N],nedge,cur[N],deep[N];
inline void aedge(int a,int b,int c){
	e[++nedge].nextt=son[a];
	son[a]=nedge;
	e[nedge].ed=b;
	e[nedge].di=c;
}
inline void insert(int a,int b,int c){
	aedge(a,b,c); aedge(b,a,0);
}
inline bool bfs(int s,int t){
	for(int i=0;i<N;i++)deep[i]=oo;
    for(int i=0;i<N;i++)cur[i]=son[i];
    deep[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int tmp=son[now];tmp;tmp=e[tmp].nextt)
            if(deep[e[tmp].ed]>=oo&&e[tmp].di){deep[e[tmp].ed]=deep[now]+1,q.push(e[tmp].ed);}
    }
    return deep[t]<oo;
}
int dfs(int now,int t,int limit){
    if(!limit||now==t) return limit;
    int flow=0,f;
    for(int tmp=cur[now];tmp;tmp=e[tmp].nextt){
        cur[now]=tmp;
        if(deep[e[tmp].ed]==deep[now]+1&&(f=dfs(e[tmp].ed,t,min(limit,e[tmp].di)))){
            flow+=f; limit-=f; e[tmp].di-=f; e[((tmp-1)^1)+1].di+=f; if(!limit)break;
        }
    }
    return flow;
}
inline int dinic(int s,int t){
    int ans=0;
    while(bfs(s,t))ans+=dfs(s,t,oo);
    return ans;
}
int n,m,k,u[605],v[605],d[605],kind[605];
vector<int> V[605];
signed main(){
	int T=read();
	while(T--){		
		n=read(); m=read(); k=read();
		int s=n+m+1,t=s+1,tot=nedge=0; for(int i=1;i<=t;i++)son[i]=0;
		for(int i=1;i<=n;i++){d[i]=0; V[i].clear();}
		for(int i=1;i<=m;i++){
			kind[i]=0;
			u[i]=read();v[i]=read();d[u[i]]++; d[v[i]]++;
			insert(n+i,u[i],1); insert(n+i,v[i],1); insert(s,n+i,1);
		}
		int flag=0,sum=0;
		for(int i=1;i<=n;i++)if(d[i]>k){
			if(d[i]>2*k){
				for(int i=1;i<=m;i++)wri(0); puts(""); flag=1; break;
			}else{
				insert(i,t,(d[i]-k)*2); sum+=(d[i]-k)*2;
			}
		}
		if(flag)continue;
		if(dinic(s,t)==sum){
			for(int i=1;i<=m;i++)if(e[2*(3*i-2)-1].di==0)V[u[i]].push_back(i);else V[v[i]].push_back(i);
			for(int i=1;i<=n;i++){
				for(unsigned j=0;j+1<V[i].size();j+=2)kind[V[i][j]]=kind[V[i][j+1]]=++tot;
			}
		}else{
			for(int i=1;i<=m;i++)wri(0); puts(""); continue;
		}
		for(int i=1;i<=m;i++)if(kind[i])wri(kind[i]); else wri(++tot); puts("");
	}
}