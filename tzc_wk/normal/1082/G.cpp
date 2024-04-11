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
#define int long long
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
int n=read(),m=read();
int head[200005];
struct edge{
	int to,nxt,cap;
} e[3000005];
int ecnt=1;
inline void addedge(int u,int v,int f){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].nxt=head[u];head[u]=ecnt;
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
	while(bfs(s,t))	tot+=dfs(s,t,0x3f3f3f3f3f3f3f3fll);
	return tot;
}
signed main(){
	fz(i,1,n){
		int x=read();
		addedge(i,n+m+1,x);
		addedge(n+m+1,i,0);
	}
	int sum=0;
	fz(i,1,m){
		int a=read(),b=read(),c=read();
		sum+=c;
		addedge(n+i,a,0x3f3f3f3f3f3f3f3fll);
		addedge(a,n+i,0);
		addedge(n+i,b,0x3f3f3f3f3f3f3f3fll);
		addedge(b,n+i,0);
		addedge(0,n+i,c);
		addedge(n+i,0,0);
	}
	cout<<sum-Dinic(0,n+m+1)<<endl;
	return 0;
}