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

int gcd(int x,int y){
    return y ? gcd(y,x%y) : x;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    map<pair<int,int>,int> mp;
    int n,k;
    cin>>n>>k;
    vector<ll> x(n),y(n),g(n);
    rep(i,n){
        cin>>x[i]>>y[i];
        if(x[i]==0&&y[i]==0)mp[{0,0}]++;
        else {
            g[i]=gcd(abs(x[i]),abs(y[i]));
            mp[{x[i]/g[i],y[i]/g[i]}]++;
        }
    }
    int idx=0;
    for(auto& e:mp)e.second=idx++;
    vector<vector<double>> pq(idx);
    rep(i,n){
        if(x[i]==0&&y[i]==0)pq[mp[{x[i],y[i]}]].push_back(0);
        else {
            pq[mp[{x[i]/g[i],y[i]/g[i]}]].push_back(sqrt(x[i]*x[i]+y[i]*y[i]));
        }
    }
    rep(i,idx)sort(pq[i].rbegin(),pq[i].rend());
    vector<int> cnt(idx,k-1);
    priority_queue<pair<double,int>> all;
    vector<int> id(idx),lid(idx);
    rep(i,idx){
        all.push({pq[i][id[i]++]*(k-1),i});
        lid[i]=pq[i].size();
    }
    double ans=0;
    vector<double> d(idx);
    rep(i,k){
        auto p = all.top();all.pop();
        ans += p.first;
        if(cnt[p.second]>=2){
            cnt[p.second]-=2;
            if(id[p.second]!=lid[p.second])all.push({pq[p.second][id[p.second]++]*cnt[p.second],p.second});
        }
        else {
            if(cnt[p.second]>=0)cnt[p.second]-=2;
            if(id[p.second]!=lid[p.second]){
                all.push({pq[p.second][--lid[p.second]]*cnt[p.second]-d[p.second],p.second});
                d[p.second]+=pq[p.second][lid[p.second]]*2;
            }
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}