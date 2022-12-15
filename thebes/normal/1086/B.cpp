#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e5+5;
ll N, S, i, x, y, deg[MN], cnt;
vector<pair<ll,ll>> adj;

int main(){
    for(scanf("%lld%lld",&N,&S),i=1;i<N;i++){
        scanf("%lld%lld",&x,&y);
        deg[x]++; deg[y]++;
        adj.push_back({x,y});
    }
    for(auto v : adj){
        if(deg[v.first]==1||deg[v.second]==1) cnt++;
    }
    if(N==2) printf("%.7lf\n",(double)S);
    else printf("%.7lf\n",2.0*S/(double)cnt);
    return 0;
}