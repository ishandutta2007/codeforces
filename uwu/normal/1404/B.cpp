#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

vector<int> graph[MAXN];
int far,best,dist[MAXN];

void dfs1(int curr, int prev){
    dist[curr]=dist[prev]+1;
    for (int x:graph[curr]){
        if (x==prev) continue;
        dfs1(x,curr);
    }
}

void dfs2(int curr, int prev, int d){
    if (d>best) far=curr, best=d; 
    for (int x:graph[curr]){
        if (x==prev) continue;
        dfs2(x,curr,d+1);
    }
}

bool solve(){
    int n,a,b,da,db; cin >> n >> a >> b >> da >> db;
    for (int i=1;i<=n;++i) graph[i].clear(), dist[n]=0;
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dist[0]=-1; dfs1(a,0);
    if (dist[b]<=da) return 1;
    best=0;
    dfs2(a,a,0); best=0;
    dfs2(far,far,0);
    return 2*da>=min(db,best);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cout << (solve()?"Alice":"Bob") << '\n';
    }
}