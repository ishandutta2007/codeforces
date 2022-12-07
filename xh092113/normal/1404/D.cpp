#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 5e5;

int n;
int pos[2*N+5];
vector<int> p[2*N+5];
bool vis[4*N+5];
bool chosen[2*N+5];
int cnt,head[2*N+5];

struct edge{
	int des,next;
}e[8*N+5];

In void addedge(int a,int b){
	cnt++;
	e[cnt].des = b;
	e[cnt].next = head[a];
	head[a] = cnt;
}

In void add(int a,int b){
	addedge(a,b);
	addedge(b,a);
}

stack<int> S;
void dfs(int u){
	S.push(u);
	for(rg int i = head[u];i;i = e[i].next){
		int v = e[i].des;
		if(vis[v])continue;
		vis[v] = 1;dfs(v);
	}
}

void findloop(int s){
	vis[s] = 1;dfs(s);
	int tot = 0;
	while(!S.empty()){
		int u = S.top();S.pop();
		tot++;
		if(tot & 1)chosen[u] = 1;
	}
}

int main(){
//	freopen("CF1404D.in","r",stdin);
//	freopen("CF1404D.out","w",stdout);
	
	scanf("%d",&n);
	if(n % 2 == 0){
		printf("First\n"),fflush(stdout);
		for(rg int i = 1;i <= n;i++)printf("%d ",i),fflush(stdout);
		for(rg int i = 1;i < n;i++)printf("%d ",i),fflush(stdout);
		printf("%d\n",n),fflush(stdout);
	}
	else{
		printf("Second\n"),fflush(stdout);
		for(rg int i = 1;i <= 2 * n;i++){
			scanf("%d",&pos[i]);
			p[pos[i]].push_back(i);
		}
		cnt = 1;
		for(rg int i = 1;i <= n;i++)add(p[i][0],p[i][1]);
		for(rg int i = 1;i <= n;i++)add(i,n + i);
		for(rg int i = 1;i <= 2 * n;i++)if(!vis[i])findloop(i);
		ll sum = 0;
		for(rg int i = 1;i <= 2 * n;i++)if(chosen[i])sum += i;
		if(sum % (2*n) != 0)
			for(rg int i = 1;i <= 2 * n;i++)chosen[i] ^= 1;
		for(rg int i = 1;i <= 2 * n;i++)if(chosen[i])printf("%d ",i),fflush(stdout);
		printf("\n"),fflush(stdout);
	}
	int re;scanf("%d",&re);
		
	return 0;
}