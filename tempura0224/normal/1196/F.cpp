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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,ll>>> v(n);
    
    using T = pair<ll, pair<int,int>> ;
    priority_queue<T,vector<T>,greater<T>> pq; 
    map<pair<int,int>, ll> dist;
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--y;
        v[x].emplace_back(y,z);
        v[y].emplace_back(x,z);
        pq.push({z,minmax(x,y)});
        dist[minmax(x,y)]=z;
    }
    rep(i,n){
        sort(v[i].begin(),v[i].end(),[](auto x,auto y){
            return x.second<y.second;
        });
    }
    int idx = 0;
    while(1){
        auto t = pq.top();pq.pop();
        ll d = t.first;
        int x = t.second.first, y = t.second.second;
        if(dist[t.second]<d)continue;
        if(++idx==k){
            cout<<d<<endl;
            return 0;
        }
        int cnt=0;
        for(auto to : v[x]){
            if(to.first==y)continue;
            auto p = minmax(to.first,y);
            if(!dist.count(p)||dist[p]>d+to.second){
                dist[p]=d+to.second;
                pq.push({d+to.second,p});
                if(++cnt==k)break;
            }
        }
        cnt=0;
        for(auto to : v[y]){
            if(to.first==x)continue;
            auto p = minmax(to.first,x);
            if(!dist.count(p)||dist[p]>d+to.second){
                dist[p]=d+to.second;
                pq.push({d+to.second,p});
                if(++cnt==k)break;
            }
        }
    }
    return 0;
}