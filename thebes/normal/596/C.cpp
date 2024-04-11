#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MN = 2e5+5;
int N, i, x, y, d[MN], s[MN];
map<pii,int> id; pii pos[MN];
vector<int> adj[MN];
vector<pii> ans;

struct pq{bool operator()(const int&i,const int&j){return adj[i].size()>adj[j].size();}};
priority_queue<int,vector<int>,pq> q[2*MN];

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d%d",&x,&y);
        id[{x,y}] = i;
        s[i] = y-x;
        pos[i] = {x,y};
    }
    for(auto v : id){
        tie(x,y) = v.first;
        if(id.count({x+1,y})){
            adj[v.second].push_back(id[{x+1,y}]);
            d[id[{x+1,y}]]++;
        }
        if(id.count({x,y+1})){
            adj[v.second].push_back(id[{x,y+1}]);
            d[id[{x,y+1}]]++;
        }
    }
    q[MN].push(id[{0,0}]);
    for(i=1;i<=N;i++){
        scanf("%d",&x);
        if(q[x+MN].empty()){
            printf("NO\n");
            return 0;
        }
        int r=x;
        x = q[x+MN].top();
        q[r+MN].pop();
        for(auto v : adj[x]){
            if((--d[v])==0)
                q[MN+s[v]].push(v);
        }
        ans.push_back(pos[x]);
    }
    printf("YES\n");
    for(auto v : ans) printf("%d %d\n",v.first,v.second);
    return 0;
}