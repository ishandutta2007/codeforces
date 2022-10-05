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
int ecnt=1,head[1000005];
struct edge{
	int to,nxt,cap,cost;
} e[100005];
inline void addedge(int u,int v,int f,int c){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].cost=c;e[ecnt].nxt=head[u];head[u]=ecnt;
}
bool vis[10005];
int dist[10005],flow[10005],pre[10005],pos[10005];
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
int n=read(),a[3005];
signed main(){
	addedge(3*n+2,0,4,0);
	addedge(0,3*n+2,0,0);
	fz(i,1,n){
		addedge(0,3*i-2,1,0);
		addedge(3*i-2,0,0,0);
		addedge(3*i-2,3*i-1,1,-1);
		addedge(3*i-1,3*i-2,0,1);
		addedge(3*i-1,3*i,1,0);
		addedge(3*i,3*i-1,0,0);
		addedge(3*i-2,3*i,0x3f3f3f3f,0);
		addedge(3*i,3*i-2,0,0);
		addedge(3*i,3*n+1,1,0);
		addedge(3*n+1,3*i,0,0);
	}
	fz(i,1,n){
		a[i]=read();
	}
	fz(i,1,n){
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]+1){
				addedge(3*i,3*j-2,0x3f3f3f3f,0);
				addedge(3*j-2,3*i,0,0);
				break;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]-1){
				addedge(3*i,3*j-2,0x3f3f3f3f,0);
				addedge(3*j-2,3*i,0,0);
				break;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])%7==0){
				addedge(3*i,3*j-2,0x3f3f3f3f,0);
				addedge(3*j-2,3*i,0,0);
				break;
			}
		}
	}
	cout<<-Dinic(3*n+2,3*n+1)<<endl;
	return 0;
}