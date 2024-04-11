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
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
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
int n=read(),m=read(),x=read(),k=read(),fr[100005],dist[610][610];
int head[100005];
struct edge{
	int to,nxt,cap;
} e[1000005];
int ecnt=1;
inline void addedge(int u,int v,int f){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].nxt=head[u];head[u]=ecnt;
}
int dep[100005];
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
inline bool check(int mid){
	ecnt=1;
	memset(head,0,sizeof(head));
	fz(i,1,x){
		addedge(0,i+n,1);
		addedge(i+n,0,0);
		fz(j,1,n){
			if(dist[fr[i]][j]<=mid){
				addedge(i+n,j,1);
				addedge(j,i+n,0);
			}
		}
	}
	fz(i,1,n){
		addedge(i,n+x+1,1);
		addedge(n+x+1,i,0);
	}
	return Dinic(0,n+x+1)>=k;
}
int main(){
	memset(dist,63,sizeof(dist));
	fz(i,1,x)	fr[i]=read();
	fz(i,1,n)	dist[i][i]=0;
	fz(i,1,m){
		int a=read(),b=read(),c=read();
		dist[a][b]=dist[b][a]=min(dist[a][b],c);
	}
	fz(k,1,n)	fz(i,1,n)	fz(j,1,n)	dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	int l=0,r=1731311,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else			l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}