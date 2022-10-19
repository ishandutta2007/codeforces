#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200001;
set<int> graph[MAXN];
int dist[MAXN];
int penalty[MAXN];
priority_queue<pii> pq;

void dfs(int node, int prev, int d){
    dist[node]=d;
    int leaf=true;
    for (auto&&x:graph[node]){
        if (x==prev) continue;
        leaf=false;
        dfs(x,node,d+1);
    }
    if (leaf){
        pq.push({d,node});
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    dfs(1,0,0);
    ll ans=0;
    int node, val;
    while (k--){
        node=pq.top().second; val=pq.top().first; pq.pop();
        ans+=val;
        int parent=*graph[node].begin();
        //cout << node << "->" << parent << ":" << val << " | ";
        graph[parent].erase(node);
        dist[parent]-=penalty[node]+1;
        penalty[parent]+=penalty[node]+1;
        if (graph[parent].size()==1&&parent!=1){
            pq.push({dist[parent],parent});
        }
    }
    cout << ans << '\n';
}