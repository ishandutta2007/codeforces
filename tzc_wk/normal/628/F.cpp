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
int n=read(),b=read(),q=read();
pair<int,int> p[10005];
int main(){
	addedge(0,b+q+10,n);
	addedge(b+q+10,0,0);
	fz(i,1,q){
		p[i].fi=read();
		p[i].se=read();
	}
	sort(p+1,p+q+1);
	fz(i,1,q-1){
		if(p[i].se>p[i+1].se){
			puts("unfair");
			return 0;
		}
	}
	p[0]={0,0};
	p[q+1]={b,n};
	fz(i,1,q+1){
		addedge(b+q+10,i,p[i].se-p[i-1].se);
		addedge(i,b+q+10,0);
	}
	fz(i,1,q+1){
		fz(j,p[i-1].fi+1,p[i].fi){
			addedge(i,q+1+j,1);
			addedge(q+1+j,i,0);
		}
	}
	fz(i,1,b){
		addedge(q+1+i,q+2+b+i%5,1);
		addedge(q+2+b+i%5,q+1+i,0);
	}
	fz(i,0,4){
		addedge(q+2+b+i,b+q+11,n/5);
		addedge(b+q+11,q+2+b+i,0);
	}
	if(Dinic(0,b+q+11)==n)	puts("fair");
	else					puts("unfair");
	return 0;
}