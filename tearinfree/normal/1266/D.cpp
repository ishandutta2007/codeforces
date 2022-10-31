#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,m;
lli cost[100001];

struct edge{
    int u,v;
    lli w;
    edge(int u,int v,lli w):u(u),v(v),w(w) {}
};

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v,w;i<m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        cost[u]+=w;
        cost[v]-=w;
    }

    vector<int> pa,na;
    for(int i=1;i<=n;i++) {
        if(cost[i] > 0) pa.push_back(i);
        else if(cost[i] < 0) na.push_back(i);
    }

    vector<edge> ret;

    for(int i=0,j=0;i<pa.size() && j<na.size();) {
        lli val = min(cost[pa[i]], -cost[na[j]]);
        cost[pa[i]] -= val; cost[na[j]] += val;
        ret.push_back(edge(pa[i],na[j],val));
        if(cost[pa[i]] == 0) i++;
        if(cost[na[j]] == 0) j++;
    }

    printf("%lu\n",ret.size());
    for(auto &it:ret) printf("%d %d %lld\n",it.u,it.v,it.w);
    
    return 0;
}