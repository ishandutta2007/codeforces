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
    int n;
    cin>>n;
    ll a[n],b[n];
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    pair<int,int> p[n];
    rep(i,n)p[i]={a[i],b[i]};
    sort(p,p+n);
    ll ans = 0;
    priority_queue<pair<ll,int>> pq;
    int cur = -inf;
    rep(i,n){
        while(cur!=p[i].first){
            if(pq.empty()){
                cur = p[i].first;
            }
            else {
                auto t = pq.top();
                pq.pop();
                ans += (cur-t.second)*t.first;
                ++cur;
            }
        }
        while(i<n && p[i].first == cur){
            pq.push({p[i].second, p[i].first});
            ++i;
        }
        auto t = pq.top();
        pq.pop();
        ans += (cur-t.second)*t.first;
        ++cur;
        --i;
    }
    while(pq.size()){
        auto t = pq.top();
        pq.pop();
        ans += (cur-t.second)*t.first;
        ++cur;
    }
    cout<<ans<<endl;
    return 0;
}