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
	int to,nxt,cap,cost;
} e[1000005];
inline void addedge(int u,int v,int f,int c){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].cost=c;e[ecnt].nxt=head[u];head[u]=ecnt;
}
bool vis[100005];
int dist[100005],flow[100005],pre[100005],pos[100005];
inline bool spfa(int s,int t){
	memset(vis,1,sizeof(vis));
	memset(dist,63,sizeof(dist));
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
//	cout<<flow[t]<<endl;
	return dist[t]<0x3f3f3f3f;
}
inline int Dinic(int s,int t){
	int sum=0;
	while(spfa(s,t)){
		sum+=flow[t]*dist[t];
		for(int i=t;i!=s;i=pos[i]){
			e[pre[i]].cap-=flow[t];
			e[pre[i]^1].cap+=flow[t];
		}
	}
	return sum;
}
int n=read(),m=read();
int mn[55],mx[55]; 
inline int id(int x,int y){
	return (x-1)*n+y;
}
signed main(){
	fz(i,1,n)	mn[i]=1,mx[i]=n; 
	fz(i,1,m){
		int opt=read(),l=read(),r=read(),x=read();
		if(opt==1){
			for(int j=l;j<=r;j++)	mn[j]=max(mn[j],x);
		}
		else{
			for(int j=l;j<=r;j++)	mx[j]=min(mx[j],x);
		}
	}
	fz(i,1,n){
		if(mn[i]>mx[i]){
			puts("-1");
			return 0;
		}
	}
	fz(i,1,n){
		addedge(0,n*n+i,1,0);
		addedge(n*n+i,0,0,0);
		addedge(n*n+n+n+n+i,5000,1,0);
		addedge(5000,n*n+n+n+n+i,0,0);
		fz(j,mn[i],mx[i]){
			addedge(n*n+i,n*n+n+j,1,0);
			addedge(n*n+n+j,n*n+i,0,0);
			addedge(n*n+n+n+j,id(i,j),1,0);
			addedge(id(i,j),n*n+n+n+j,0,0);
			addedge(id(i,j),n*n+n+n+n+i,1,0);
			addedge(n*n+n+n+n+i,id(i,j),0,0);
		}
	}
	fz(i,1,n){
		fz(j,1,n){
			addedge(n*n+n+i,n*n+n+n+i,1,2*j-1);
			addedge(n*n+n+n+i,n*n+n+i,0,-(2*j-1));
		}
	}
	cout<<Dinic(0,5000)<<endl;
	return 0;
}