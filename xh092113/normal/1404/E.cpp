#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 200;
const int inf = 0x3f3f3f3f;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int a[N+5][N+5];
int n,m;
char s[N+5];

struct edge{
	int to,next,flow;
}e[8*N*N+5];
int S,T,cnt,head[N*N+5],iter[N*N+5],dep[N*N+5];

In int id(int i,int j){
//cout<<"id: i="<<i<<" j="<<j<<endl;
	return (i - 1) * m + j;
}
In void addedge(int u,int v,int f){
	cnt++;
	e[cnt].to = v;
	e[cnt].flow = f;
	e[cnt].next = head[u];
	head[u] = cnt;
}
In void add(int u,int v,int f){
	addedge(u,v,f);
	addedge(v,u,0);
}
queue<int> Q;
bool bfs(){
	Q.push(S);
	memcpy(iter,head,sizeof(iter));
	memset(dep,0x3f,sizeof(dep));
	dep[S] = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(rg int i = head[u];i;i = e[i].next){
			int v = e[i].to;
			if(!e[i].flow || dep[v] != inf)continue;
			dep[v] = dep[u] + 1;
			Q.push(v);
		}
	}
	return dep[T] != inf;
}
In int dfs(int u,int f){
	if(u == T)return f;
	int g = 0;
	for(rg int i = iter[u];i;i = e[i].next,iter[u] = i){
		int v = e[i].to;
		if(dep[v] != dep[u] + 1 || !e[i].flow)continue;
		int d = dfs(v,min(e[i].flow,f));
		g += d,f -= d,e[i].flow -= d,e[i^1].flow += d;
		if(!f)break;
	}
	if(!g)dep[u] = inf;
	return g;
}
In int dinic(){
	int fs = 0;
	while(bfs())fs += dfs(S,inf);
	return fs;
}

int main(){
//	freopen("CF1404E.in","r",stdin);
//	freopen("CF1404E.out","w",stdout);
	
	n = read(),m = read();
	cnt = 1,S = 0,T = n * m + 1;
	for(rg int i = 1;i <= n;i++){
		scanf("%s",s + 1);
		for(rg int j = 1;j <= m;j++)if(s[j] == '.')a[i][j] = 0;
		else a[i][j] = 1;
	}
/*for(rg int i = 0;i <= n + 1;i++){
	for(rg int j = 0;j <= m + 1;j++)cout<<a[i][j]<<" ";cout<<endl;
}*/
	for(rg int i = 1;i <= n;i++)
		for(rg int j = 1;j <= m;j++)if(a[i][j]){
			if(!a[i][j-1])add(id(i,j),T,1);else add(id(i,j),id(i,j-1),1);
			if(!a[i-1][j])add(S,id(i,j),1);else add(id(i-1,j),id(i,j),1);
		}	
//cout<<"cnt="<<cnt<<endl;
	write(dinic());putchar('\n');
	
	return 0;
}