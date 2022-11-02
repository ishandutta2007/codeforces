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
const int N=205,M=20005,inf=1e9,P=M;
int di[M],nxt[M],ed[M];
int son[N],nedge,cur[N],deep[N];
inline void aedge(int a,int b,int c){
	nxt[++nedge]=son[a]; 
	son[a]=nedge;
	ed[nedge]=b;
	di[nedge]=c;
}
inline void insert(int a,int b,int c){
	//cout<<a<<" "<<b<<" "<<c<<endl;
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
bool vis[N],heshu[P];
int a[N];
vector<int> v[N];
void GG(){
	puts("Impossible"); exit(0);
}
int main(){
	For(i,2,P-1)if(!heshu[i]){
		for(int j=i+i;j<P;j+=i)heshu[j]=1;
	}
	int n=read(),s=n+1,t=n+2;
	if(n&1)GG();
	For(i,1,n)a[i]=read();
	For(i,1,n){
		if(a[i]%2==1){
			insert(s,i,2);
			For(j,1,n)if(!heshu[a[i]+a[j]]){
				insert(i,j,1);
			}
		}else insert(i,t,2);
	}
	if(dinic(s,t)!=n)GG(); 
	For(i,1,n)if(a[i]&1)for(int j=son[i];j;j=nxt[j])if(ed[j]!=s&&di[j]==0){
		v[i].pb(ed[j]);
		v[ed[j]].pb(i);
	}
	vector<vector<int> > an;
	For(i,1,n)if(!vis[i]){
		vector<int> zs;
		for(int j=i;!vis[j];j=vis[v[j][0]]?v[j][1]:v[j][0]){vis[j]=1; zs.pb(j);}
		an.pb(zs);
	}
	writeln(an.size());
	for(auto i:an){
		wri(i.size());
		for(auto j:i)wri(j); puts("");
	}
}