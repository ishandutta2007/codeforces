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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,int>> v[n];
    rep(i,m){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        --x;--y;
        v[x].emplace_back(z,y);
        v[y].emplace_back(z,x);
    }
    vector<ll> dist(n,longinf);
    rep(i,k){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;
        dist[x]=min(dist[x],(ll)y);
    }
    rep(i,n){
        if(dist[i]!=longinf)v[0].emplace_back(dist[i],i);
    }

    vector<ll>dist2(n, longinf), cnt(n,0);
    priority_queue<pair<ll,int>> que;
    dist2[0]=0;
    que.emplace(0,0);
    while(que.size()){
        ll d=-que.top().first;
        int x=que.top().second;
        que.pop();
        if(dist2[x]<d)continue;
        for(auto p:v[x]){
            int to =p.second;
            ll cost=p.first;
            if(dist2[to]>dist2[x]+cost){
                dist2[to]=dist2[x]+cost;
                cnt[to]=1;
                que.emplace(-dist2[to],to);
            }
            else if(dist2[to]==dist2[x]+cost&&cnt[to]<2)++cnt[to];
        }
    }
    int ans = 0 ;
    rep(i,n){
        if(dist[i]==dist2[i]&&cnt[i]==1)++ans;
    }
    cout<<k-ans<<endl;
    return 0;
}