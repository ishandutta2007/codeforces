#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set> 
using namespace std;
#define ll long long
const int maxn=100009;
int n,m,cur,head[maxn],tot;
ll a[maxn];
struct pp{int nxt,to;}g[maxn<<2];
struct Matrix{int id;ll val;}t[maxn];int d[maxn<<2];
void add(int u,int v){
	g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;d[v]++;
}
bool cmp(Matrix x,Matrix y){return x.val<y.val;}
int ans[maxn],pos;
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);cur=m;
	memset(head,-1,sizeof(head));tot=0;
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[j]);
			if(a[j]!=-1) t[++cnt].id=j,t[cnt].val=a[j];
		}
		sort(t+1,t+cnt+1,cmp);
		if(cnt==1) continue;
		for(int i=1;i<=cnt;i++){
			if(i==1||t[i-1].val!=t[i].val) cur++; 
			add(cur,t[i].id);add(t[i].id,cur+1);
		}
		cur++;
	}
	pos=0;
	for(int i=1;i<=cur;i++)
		if(!d[i]) q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(u<=m&&u>=1) ans[++pos]=u;
		for(int i=head[u];i!=-1;i=g[i].nxt){
			int v=g[i].to;
			d[v]--;if(!d[v]) q.push(v);
		}
	}	
	if(pos<m) printf("-1\n");
	else for(int i=1;i<=pos;i++)
		printf("%d ",ans[i]);
	return 0;
}