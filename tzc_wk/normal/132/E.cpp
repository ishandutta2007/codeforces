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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),a[255];
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
	flow[s]=0x3f3f3f3f3f3f3f3fll;
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
int by[100005],used[30];
vector<pair<int,int> > d;
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n){
		addedge(i,i+n,1,__builtin_popcount(a[i]));
		addedge(i+n,i,0,-__builtin_popcount(a[i]));
		addedge(i+n,i+n+n,1,-0x3f3f3f3f3fll);
		addedge(i+n,i+n+n,0,0x3f3f3f3f3fll);
		if(i!=n){
			addedge(i,i+1,m,0);
			addedge(i+1,i,0,0);
			addedge(i+n+n,i+1,1,0);
			addedge(i+1,i+n+n,0,0);
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]){
				addedge(i+n+n,j+n,1,0);
				addedge(j+n,i+n+n,0,0);
				break;
			}
		}
	}
	addedge(0,1,m,0);
	addedge(1,0,0,0);
	addedge(3*n,3*n+1,m,0);
	addedge(3*n+1,3*n,0,0);
	addedge(n,3*n+1,m,0);
	addedge(3*n+1,n,0,0);
	int ans=Dinic(0,3*n+1)+0x3f3f3f3f3fll*n;
	fz(i,1,n){
		for(int j=head[i+n];j;j=e[j].nxt){
			int t=e[j].to;
			if(t==i){
				if(e[j].cap==1){
					for(int k=0;k<m;k++){
						if(!used[k]){
							used[k]=1;
							by[i]=k;
							d.push_back({k,a[i]});
							d.push_back({k,0});
							break;
						}
					}
					break;
				}
			}
			else if(t!=i+n*2){
				if(e[j].cap==1){
					by[i]=by[t-(n<<1)];
					d.push_back({by[i],0});
					break;
				}
			}
		}
		for(int j=head[i+n+n];j;j=e[j].nxt){
			int t=e[j].to;
			if(t==i+1){
				if(e[j^1].cap==1){
					used[by[i]]=0;
				}
				break;
			}
		}
	}
	cout<<d.size()<<" "<<ans<<endl;
	foreach(it,d){
		if(it->second==0){
			cout<<"print("<<char(it->first+'a')<<")\n";
		}
		else{
			cout<<char(it->first+'a')<<"="<<it->second<<endl;
		}
	}
	return 0;
}