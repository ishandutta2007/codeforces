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
int head[100005],ecnt=1;
struct edge{
	int to,nxt,cap;
	double cost;
} e[1000005];
inline void addedge(int u,int v,int f,double c){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].cost=c;e[ecnt].nxt=head[u];head[u]=ecnt;
	e[++ecnt].to=u;e[ecnt].cap=0;e[ecnt].cost=-c;e[ecnt].nxt=head[v];head[v]=ecnt;
}
bool vis[100005];
double dist[100005];
int flow[100005],pre[100005],pos[100005],fl=0;
inline bool spfa(int s,int t){
	memset(vis,1,sizeof(vis));
	fz(i,0,100000)	dist[i]=1e9;
	queue<int> q;
	vis[s]=0;
	dist[s]=0;
	flow[s]=0x3f3f3f3f;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
//		cout<<x<<endl;
		vis[x]=true;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
//			cout<<y<<endl;
			if(e[i].cap>0&&dist[y]>dist[x]+e[i].cost){
				dist[y]=dist[x]+e[i].cost;pos[y]=x;pre[y]=i;
				flow[y]=min(flow[x],e[i].cap);
//				cout<<flow[y]<<endl;
				if(vis[y]){
					q.push(y);
					vis[y]=false;
				}
			}
		}
		q.pop();
	}
	return dist[t]<1e9;
}
inline double Dinic(int s,int t){
	double sum=0;
	while(spfa(s,t)){
		sum+=flow[t]*dist[t];
		fl+=flow[t];
		for(int i=t;i!=s;i=pos[i]){
			e[pre[i]].cap-=flow[t];
			e[pre[i]^1].cap+=flow[t];
		}
	}
	return sum;
}
pair<int,int> p[405];
int n=read();
signed main(){
	fz(i,1,n)	p[i].se=read(),p[i].fi=read();
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	fz(i,1,n){
		addedge(0,i,2,0);
		fz(j,i+1,n){
			if(p[i].fi>p[j].fi)	addedge(i,j+n,1,sqrt((p[i].fi-p[j].fi)*(p[i].fi-p[j].fi)+(p[i].se-p[j].se)*(p[i].se-p[j].se)));
		}
		if(i!=1)	addedge(i+n,2*n+1,1,0);
	}
	double ans=Dinic(0,2*n+1);
	if(fl!=n-1)	puts("-1");
	else		printf("%.19lf\n",ans);
	return 0;
}