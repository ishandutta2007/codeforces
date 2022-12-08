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
    ll n,m,d;
    cin>>n>>m>>d;
    vector<ll> dp(n);
    ll cur=0;
    rep(_,m){
        ll a,b,t;
        cin>>a>>b>>t;
        --a;
        deque<pair<ll,int>> dq;
        vector<ll> ndp(n);
        int j=0;
        rep(i,n){
            while(abs(j-i)<=d*(t-cur)&&j<n){
                while(!dq.empty()&&dq.back().first<=dp[j]){
                    dq.pop_back();
                }
                dq.emplace_back(dp[j],j);
                ++j;
            }
            while(!dq.empty()&&abs(dq.front().second-i)>d*(t-cur)){
                dq.pop_front();
            }
            assert(!dq.empty());
            ndp[i]=b-abs(a-i)+dq.front().first;
        }
        dp.swap(ndp);
        cur=t;
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
    return 0;
}