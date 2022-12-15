#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2e5+5;
map<int,int> X, Y;
int n, i, x, y, col[MN], d[MN], nxt;
queue<pii> adj[2*MN];

void go(int n,int c){
    while(adj[n].size()){
        pii g = adj[n].front(); adj[n].pop();
        if(d[g.second]) continue;
        col[g.second]=c; d[g.second]=1;
        go(g.first, !c);
        return;
    }
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        if(!X.count(x)) X[x]=++nxt;
        if(!Y.count(y)) Y[y]=++nxt;
        adj[X[x]].push({Y[y],i});
        adj[Y[y]].push({X[x],i});
    }
    for(i=1;i<=nxt;i++){
        int f = 0;
        while(adj[i].size()){
            go(i, f);
            f = !f;
        }
    }
    for(i=1;i<=n;i++) printf("%c",col[i]?'r':'b');
    printf("\n");
    return 0;
}