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
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> v(n);
    int cur = n;
    REP(i,1,m+1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        int d = 1,c = 0;
        while(d<=i){
            c++;
            d*=10;
        }
        rep(j,c-1)v.push_back({});
        int cop = i;
        if(c>=2){
            rep(_,2){
            cop=i;
            v[cur].emplace_back(cop%10,y);
            rep(j,c-2){
                cop/=10;
                v[cur+j+1].emplace_back(cop%10,cur+j);
            }
            cop/=10;
            v[x].emplace_back(cop,cur+c-2);
            swap(x,y);
            }
            cur += c-1;
        }
        else {
            v[y].emplace_back(i,x);
            v[x].emplace_back(i,y);
        }
    }
    rep(i,cur){
        sort(v[i].begin(),v[i].end());
    }
    queue<int> q;
    vector<ll> dist(cur,-1),dist2(cur,inf);
    dist[0]=0;
    q.push(0);
    queue<int> pq[10];
    ll pre = -1;
    while(1){
        if(q.empty()||dist[q.front()]!=pre){
            rep(i,10){
                while(pq[i].size()){
                    int x = pq[i].front();pq[i].pop();
                    if(dist2[x]==i){
                        q.push(x);
                        dist2[x]=-1;
                    }
                }
            }
        }
        if(q.empty())break;
        int c = q.front();q.pop();
        for(auto e : v[c]){
            if(dist2[e.second]<=e.first)continue;
            dist[e.second]=(dist[c]*10+e.first)%mod;
            dist2[e.second]=e.first;
            pq[e.first].push(e.second);
        }
        pre=dist[c];
    }
    rep(i,n-1){
        cout<<dist[i+1]<<"\n";
    }
    return 0;
}