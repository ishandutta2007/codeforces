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
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, ll>>> v(4*n);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--y;
        rep(i,4){
            v[n*i+x].emplace_back(n*i+y,z);
            if(!(i&2))v[n*i+x].emplace_back(n*(i|2)+y, 2*z);
            if(!(i&1))v[n*i+x].emplace_back(n*(i|1)+y, 0);
        }
        v[x].emplace_back(3*n+y,z);
        v[y].emplace_back(3*n+x,z);
        rep(i,4){
            v[n*i+y].emplace_back(n*i+x,z);
            if(!(i&2))v[n*i+y].emplace_back(n*(i|2)+x, 2*z);
            if(!(i&1))v[n*i+y].emplace_back(n*(i|1)+x, 0);
        }
    }
    vector<ll> dist(4*n, longinf);
    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0,0);
    dist[0]=0;
    while(pq.size()){
        auto p = pq.top();pq.pop();
        ll d = p.first, x = p.second;
        if(dist[x]<d)continue;
        for(auto to: v[x]){
            if(dist[to.first]>d+to.second){
                dist[to.first]=d+to.second;
                pq.emplace(dist[to.first],to.first);
            }
        }
    }
    rep(i,n-1)cout<<dist[3*n+i+1]<<" ";
    cout<<endl;
    return 0;
}