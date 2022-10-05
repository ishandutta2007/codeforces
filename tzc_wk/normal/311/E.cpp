//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int head[200005];
struct edge{
	int to,nxt,cap;
} e[3000005];
int ecnt=1;
inline void addedge(int u,int v,int f){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].nxt=head[u];head[u]=ecnt;
	e[++ecnt].to=u;e[ecnt].cap=0;e[ecnt].nxt=head[v];head[v]=ecnt;
}
int dep[200005];
inline bool bfs(int s,int t){
	queue<int> q;
	memset(dep,-1,sizeof(dep));
	q.push(s);dep[s]=0;
	while(!q.empty()){
		int cur=q.front();q.pop();
		for(int i=head[cur];i;i=e[i].nxt){
			int to=e[i].to;
			if(dep[to]==-1&&e[i].cap){
				dep[to]=dep[cur]+1;
				q.push(to);
			}
		}
	}
	if(dep[t]!=-1)	return 1;
	return 0;
}
inline int dfs(int x,int t,int f){
	if(x==t)	return f;
	int ret=0;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(dep[y]==dep[x]+1&&e[i].cap){
			int w=dfs(y,t,min(f-ret,e[i].cap));
			e[i].cap-=w;
			e[i^1].cap+=w;
			ret+=w;
			if(ret==f)	return f;
		}
	}
	if(ret==0)	dep[x]=-1;
	return ret;
}
inline int Dinic(int s,int t){
	int tot=0;
	while(bfs(s,t))	tot+=dfs(s,t,0x3f3f3f3f);
	return tot;
}
int n=read(),m=read(),g=read(),a[10005],b[10005],ans=0,sum=0;
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n)	b[i]=read();
	fz(i,1,n){
		if(a[i]==1)	addedge(i+m,50000,b[i]);
		else		addedge(0,i+m,b[i]);
	}
	fz(i,1,m){
		int t=read(),x=read(),y=read();
		fz(j,1,y){
			int _=read();
			if(t==0)	addedge(i,_+m,0x3f3f3f3f);
			else		addedge(_+m,i,0x3f3f3f3f);
		}
		int cond=read(),h=0;
		if(cond==0)	h=x;
		else		h=x+g,ans-=g;
		if(t==0)	addedge(0,i,h);
		else		addedge(i,50000,h);
		sum+=h;
	}
	cout<<ans+sum-Dinic(0,50000)<<endl;
	return 0;
}