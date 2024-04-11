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
int ecnt=1,head[1000005];
struct edge{
	int to,nxt,cap,cost;
} e[5000005];
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
	return dist[t]<0x3f3f3f3f3f3f3f3fll;
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
int n=read(),m=read(),k=read(),c=read(),d=read();
inline int id(int x,int y){
	return x*(n+1)+y;
}
signed main(){
	fz(i,1,k){
		int x=read();
		addedge(0,id(1,x),1,0);
		addedge(id(1,x),0,0,0);
	}
	fz(i,1,m){
		int u=read(),v=read();
		fz(j,1,99){
			fz(l,1,k){
				addedge(id(j,u),id(j+1,v),1,(l*2-1)*d+c);
				addedge(id(j+1,v),id(j,u),0,-((l*2-1)*d+c));
				addedge(id(j,v),id(j+1,u),1,(l*2-1)*d+c);
				addedge(id(j+1,u),id(j,v),0,-((l*2-1)*d+c));
			}
		}
	}
	fz(i,1,99){
		fz(j,2,n){
			addedge(id(i,j),id(i+1,j),0x3f3f3f3f,c);
			addedge(id(i+1,j),id(i,j),0,-c);
		}
		addedge(id(i,1),id(i+1,1),0x3f3f3f3f,0);
		addedge(id(i+1,1),id(i,1),0,0);
	}
	cout<<Dinic(0,id(100,1))<<endl;
	return 0;
}