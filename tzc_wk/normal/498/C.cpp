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
int a[105];
vector<pair<int,int> > fac[100];
inline void prime_deconstruction(int x){
	int tmp=a[x];
	for(int i=2;i*i<=tmp;i++){
		if(tmp%i==0){
			int cnt=0;
			while(tmp%i==0)	tmp/=i,cnt++;
			fac[x].push_back({i,cnt});
		}
	}
	if(tmp>1)	fac[x].push_back({tmp,1});
}
int n=read(),m=read();
inline int id(int x,int y){
	return y*n+x;
}
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n)	prime_deconstruction(i);
	fz(i,1,m){
		int x=read(),y=read();
		if(x&1)	swap(x,y);
		for(int j=0;j<fac[x].size();j++){
			for(int k=0;k<fac[y].size();k++){
				if(fac[x][j].first==fac[y][k].first){
//					cout<<x<<" "<<y<<" "<<fac[x][j].first<<endl;
					addedge(id(x,j),id(y,k),min(fac[x][j].second,fac[y][k].second));
					addedge(id(y,k),id(x,j),0);
				}
			}
		}
	}
	fz(i,1,n){
		if(i&1){
			for(int j=0;j<fac[i].size();j++){
				addedge(id(i,j),100000,fac[i][j].second);
				addedge(100000,id(i,j),0);
			}
		}
		else{
			for(int j=0;j<fac[i].size();j++){
				addedge(0,id(i,j),fac[i][j].second);
				addedge(id(i,j),0,0);
			}
		}
	}
	cout<<Dinic(0,100000)<<endl;
	return 0;
}