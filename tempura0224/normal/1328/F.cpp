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
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    rep(i,n){
        int x;cin>>x;
        mp[x]++;
    }
    int m = mp.size();
    vector<ll> cnt(m+1), sum(m+1), a(m+1);
    int i=0;
    for(auto p : mp){
        ++i;
        cnt[i]+=p.second;
        sum[i]+=(ll)p.second*p.first;
        a[i]=p.first;
    }
    rep(i,m)sum[i+1]+=sum[i];
    rep(i,m)cnt[i+1]+=cnt[i];
    ll ans = longinf;
    rep(i,m){
        int l = cnt[i], r = cnt[m]-cnt[i+1];
        ll sl = sum[i], sr = sum[m]-sum[i+1];
        if(cnt[i+1]-cnt[i]>=k){
            cout<<0<<endl;
            return 0;
        }
        if(cnt[i+1]-cnt[i]+l>=k){
            ans = min(ans, (a[i+1]-1)*l - sl + k-cnt[i+1]+cnt[i]);
        }
        if(cnt[i+1]-cnt[i]+r>=k){
            ans = min(ans, sr - (a[i+1]+1)*r + k-cnt[i+1]+cnt[i]);
        }
        ans = min(ans, (a[i+1]-1)*l - sl + sr - (a[i+1]+1)*r + k - cnt[i+1]+cnt[i]);
    }
    cout<<ans<<endl;
    return 0;
}