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
int head[100005];
struct edge{
	int to,nxt,cap;
} e[3000005];
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
int n=read(),a[205];
bool vis[20005];
inline void init(){
	for(int i=2;i<=20000;i++){
		if(!vis[i]){
			for(int j=i*2;j<=20000;j+=i){
				vis[j]=1;
			}
		}
	}
}
vector<int> pth[205];
int ans=0,used[205];
inline void dfss(int x){
	pth[ans].push_back(x);
//	cout<<"x="<<x<<endl;
	used[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
//		cout<<y<<"\n";
		if(y!=0&&y!=(n+1)&&!used[y]&&e[i|1].cap==1){
			dfss(y);
		}
	}
//	puts("");
}
signed main(){
	init();
	fz(i,1,n)	a[i]=read();
	fz(i,1,n){
		if(a[i]&1){
			addedge(0,i,2);
			addedge(i,0,0);
		}
		else{
			addedge(i,n+1,2);
			addedge(n+1,i,0);
		}
	}
	fz(i,1,n)	if(a[i]&1)	fz(j,1,n)	if(a[i]^1&1&&!vis[a[i]+a[j]]){
//		cout<<i<<" "<<j<<endl;
		addedge(i,j,1);
		addedge(j,i,0);
	}
	if(Dinic(0,n+1)!=n){
		puts("Impossible");
		return 0;
	}
	fz(i,1,n)	if(!used[i])	ans++,dfss(i);
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++){
		cout<<pth[i].size()<<" ";
		foreach(it,pth[i])	cout<<*it<<" ";
		puts("");
	}
	return 0;
}