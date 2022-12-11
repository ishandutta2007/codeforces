//update from https://www.luogu.com.cn/record/14825856
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define max_n 300000
#define max_m 600000
#define INF 2147483647
using namespace std;
//???: 
struct note{
    int before,v;
};
struct edge_set {
	note edge[max_m + 1];
	int last[max_n + 1];
	int cnt;
	void build(int n) {
		int i;
		cnt = 0;
		for(i = 1; i <= n; i ++)
			last[i] = -1;
	}
	edge_set(int n){
		build(n);
	}
	edge_set(){
	}
	void add(int u,int v) {
		cnt ++;
		edge[cnt].v = v;
		edge[cnt].before = last[u];
		last[u] = cnt;
	}
};
struct edge_set_vector {
	vector <note> edge;
	int last[max_n + 1];
	int cnt;
	void build(int n) {
		int i;
		cnt = 0;
		for(i = 1; i <= n; i ++)
			last[i] = -1;
	}
	edge_set_vector(int n){
		build(n);
		note tmp;
		tmp.before=0,tmp.v=0;
		edge.push_back(tmp);
	}
	edge_set_vector(){
		note tmp;
		tmp.before=0,tmp.v=0;
		edge.push_back(tmp);
	}
	void add(int u,int v) {
		note tmp;
		cnt ++;
		tmp.v = v;
		tmp.before = last[u];
		edge.push_back(tmp);
		last[u] = cnt;
	}
};
edge_set map1,map2;
edge_set_vector edge_to_end;
int w[max_n+1];
int low[max_n+1],pre[max_n+1],into[max_n+1];
int stack[max_n+1];
bool vis[max_n+1],ended[max_n+1];
int par[max_n+1],num[max_n+1],p[max_n+1];
int point[max_n+1];
int _count,sum,ans,answer;

int tarjan(int top,int p=-1){
    if(ended[top])
        return INF;
    if(vis[top])
        return low[top];
    int i,idx,x;
    _count ++;
    pre[top] = low[top] = _count;
    sum ++;
    idx = sum;
    stack[sum] = top;
    vis[top] = 1;
    for(i = map1.last[top]; ~ i; i = map1.edge[i].before){
    	if(map1.edge[i].v == p)
    		continue;
        x = tarjan(map1.edge[i].v,top);
        if(x == INF){
        	edge_to_end.add(top,num[map1.edge[i].v]);
            continue;
        }
        if(x < low[top])
            low[top] = x;
    }
    if(low[top] == pre[top]){
        ans ++;
        point[ans] = 0;
        while(sum >= idx){
            num[stack[sum]] = ans;
            par[stack[sum]] = top;
            ended[stack[sum]] = 1;
            for(i = edge_to_end.last[stack[sum]]; ~i; i = edge_to_end.edge[i].before){
            	map2.add(ans,edge_to_end.edge[i].v);
            	map2.add(edge_to_end.edge[i].v,ans);
                into[edge_to_end.edge[i].v] ++;
			}
            point[ans] += w[stack[sum]];
            sum --;
        }
        return INF;
    }
    return low[top];
}
void solve(int n){
    int i;
    memset(vis,0,sizeof(vis));
    edge_to_end.build(n);
    _count = sum = ans = 0;
    for(i = 1; i <= n; i ++){
        if(vis[i])
            continue;
        tarjan(i);
    }
}
int dp[max_n + 1];
void dfs(int top){
    if(dp[top])
        return;
    if(!(~map2.last[top])){
        dp[top] = point[top];
        return;
    }
    int i;
    for(i = map2.last[top]; ~ i; i = map2.edge[i].before){
        dfs(map2.edge[i].v);
        dp[top] = max(dp[top],dp[map2.edge[i].v]);
    }
    dp[top] += point[top];
}
int n,m;
void input(){
    int i,u,v;
    scanf("%d%d",& n,& m);
    map1.build(n);
    map2.build(n);
    for(i = 1; i <= m; i ++){
        scanf("%d%d",& u,& v);
        map1.add(u,v);
        map1.add(v,u);
    }
}
int away(edge_set& map1,int n,int s,int &dis,int p=0){
	int d=0,ret=s,v,x,i;
	for(i = map1.last[s]; ~i; i = map1.edge[i].before){
		if(map1.edge[i].v == p)
			continue;
		v = away(map1,n,map1.edge[i].v,x,s);
		if(x >= d){
			d = x+1;
			ret = v;
		}
	}
	dis = d;
	return ret;
}
int diameter(edge_set& map1,int n){
	int ret;
	away(map1,n,away(map1,n,1,ret),ret);
	return ret;
}
int main(){
    int i;
    input();
    solve(n);
    printf("%d\n",diameter(map2,ans));
    return 0;
}