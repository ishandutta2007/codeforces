#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,ll>>> v(n);
    map<pair<int,int>,int> mp;
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--y;
        v[x].emplace_back(y,z);
        v[y].emplace_back(x,z);
        mp[{x, y}]=i+1;
        mp[{y, x}]=i+1;
    }
    vector<ll> dist(n, longinf);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>,greater<>> pq;
    dist[0]=0;
    pq.emplace(0,0);
    while(pq.size()){
        auto p = pq.top();pq.pop();
        ll x = p.second, d=p.first;
        if(dist[x]<d)continue;
        for(auto to: v[x]){
            if(dist[to.first]>dist[x]+to.second){
                dist[to.first]=dist[x]+to.second;
                pq.emplace(dist[to.first],to.first);
            }
        }
    }
    vector<int> chi(n, -1), p(n, -1), used(n, 0);
    vector<int> ans;
    auto dfs = [&](auto&& self, int x)-> void {
        used[x] = 1;
        for(auto to: v[x]){
            if(used[to.first])continue;
            if(dist[x]+to.second!=dist[to.first])continue;
            ans.push_back(mp[{to.first,x}]);
            p[to.first]=x;
            chi[x]=to.first;
            self(self, to.first);
        }
    };
    dfs(dfs,0);
    while(ans.size()>k)ans.pop_back();
    cout<<ans.size()<<endl;
    for(auto e: ans)cout<<e<<" ";
    cout<<endl;
    return 0;
}