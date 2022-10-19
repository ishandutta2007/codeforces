#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int M = N;

int n , m , x , y , ans, tot , all;

int dfn[N] , scc_no[N] , fir[N] , ne[M] , to[M] , cnt , low[N] , dfs_clock, stk[N] ,  scc_num , col[N];
bool vis[N];

void add(int x , int y){
    ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

vector <int>P[N];

void dfs(int x) {
    dfn[x] = low[x] = ++ dfs_clock; stk[++ tot] = x; vis[x] = 1;
    Foreachson(i , x) {
	int V = to[i];
	if(dfn[V]) {
	    if(!col[V]) low[x] = min(low[x] , low[V]);
	}
	else dfs(V) , low[x] = min(low[x] , low[V]);
    }
    if(low[x] == dfn[x]) {
	for(++ scc_num;;) {
	    P[scc_num].push_back(stk[tot]);
	    col[stk[tot --]] = scc_num;
	    if(stk[tot + 1] == x) break;
	}
    }
}

bool used[N];
int dis[N];

int dance(int x) {
    queue<int>q; while(!q.empty()) q.pop();
    q.push(x); memset(used , 0 , sizeof(used));memset(dis , 0 , sizeof(dis));
    used[x] = 1; dis[x] = 1;
    while(!q.empty()) {
	int cur = q.front(); q.pop();
	Foreachson(i , cur) {
	    int V = to[i];
	    if(V == x) return dis[cur];
	    if(!used[V] && col[V] == col[x]) {
		used[V] = 1; q.push(V); dis[V] = dis[cur] + 1;
	    }
	}
    }
    return -2e9;
}

bool why[N];

int solve(int x) {
    int Min = P[x].size();
    for(int i = 0;i < (int) P[x].size();++ i) {
	Min = min(Min , dance(P[x][i]));
    }
    return Min;
}

int main(void) {
    scanf("%d%d" , &n , &m);
    for(int i = 1;i <= m;++ i) {
	scanf("%d%d" , &x , &y); add(x , y);
    }
    for(int i = 1;i <= n;++ i) if(!vis[i]) dfs(i);
    for(int i = 1;i <= n;++ i) {
	Foreachson(j , i) {
	    int V = to[j];
	    if(col[V] == col[i]) continue;
	    why[col[i]] = 1;
	}
    }
    for(int i = 1;i <= scc_num;++ i) if(!why[i]) {
	if(P[i].size() == 1) continue;
	ans += 998 * solve(i) + 1;
    }
    ans += n;
    cout << ans << endl;
}