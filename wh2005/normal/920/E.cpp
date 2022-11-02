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
int n,m,head[200009],tot;
struct pp{int nxt,to;}g[400009];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
int l[200009],r[200009],c[200009],vis[200009];
queue<int>q;
int bfs(int x){
	int sum=1;
	while(!q.empty()) q.pop();
	q.push(x);vis[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=g[i].nxt) c[g[i].to]=1;
		int t=0;
		while(r[t]!=n+1){
			t=r[t];
			if(c[t]) continue;
			if(!vis[t]){
				vis[t]=1;q.push(t);sum++;
				r[l[t]]=r[t],l[r[t]]=l[t];
			}
		}
		for(int i=head[u];i!=-1;i=g[i].nxt) c[g[i].to]=0;
	}
	return sum;
}
int ans[200009],cnt;
int main() {
	for(int i=1;i<=n;i++) vis[i]=0,c[i]=0;
	memset(head,-1,sizeof(head));tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
	}
	for(int i=1;i<=n+1;i++) l[i]=i-1;
	for(int i=0;i<=n;i++) r[i]=i+1;
	cnt=0;
	for(int i=1;i<=n;i++) if(!vis[i]) ans[++cnt]=bfs(i);
	printf("%d\n",cnt);
	sort(ans+1,ans+cnt+1);
	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
	return 0;
}