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
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
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
int n1=read(),n2=read(),m=read();
int u[2005],v[2005];
int head[5005];
struct edge{
	int to,nxt,cap;
} e[3000005];
int ecnt=1;
inline void addedge(int u,int v,int f){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].nxt=head[u];head[u]=ecnt;
}
int dep[5005];
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
int id[2005],deg[4005];
vector<int> ans[2005];
signed main(){
	fz(i,1,m){
		u[i]=read();v[i]=read();v[i]+=n1;
		deg[u[i]]++;deg[v[i]]++;
	}
	int k=0x3f3f3f3f;
	fz(i,1,n1+n2)	k=min(k,deg[i]);
	fz(j,1,n1){
		addedge(0,j,deg[j]-k);
		addedge(j,0,0);
	}
	fz(j,n1+1,n1+n2){
		addedge(j,5000,deg[j]-k);
		addedge(5000,j,0);
	}
	fz(j,1,m){
		addedge(u[j],v[j],1);
		addedge(v[j],u[j],0);
		id[j]=ecnt;
	}
	fd(i,k,0){
		Dinic(0,5000);
		fz(j,1,m){
			if(e[id[j]].cap==0){
				ans[i].push_back(j);
			}
		}
		for(int i=head[0];i;i=e[i].nxt)	e[i].cap++;
		for(int i=head[5000];i;i=e[i].nxt)	e[i^1].cap++;
	}
	fz(i,0,k){
		cout<<ans[i].size()<<" ";
		foreach(it,ans[i])	cout<<*it<<" ";
		puts("");
	}
	return 0;
}