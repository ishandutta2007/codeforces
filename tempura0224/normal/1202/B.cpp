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

int calc(int res, int  a, int b){
    int ans = inf;
    rep(i,11)rep(j,11){
        if(i==0&&j==0)continue;
        if((a*i+b*j)%10==res)ans = min(ans, i+j);
    }
    if(ans == inf)return -1;
    return ans-1;
}

int main(){
    string s;
    cin>>s;
    int n =s.size();
    vector<ll> cnt(10);
    rep(i,n-1){
        cnt[(s[i+1]-s[i]+10)%10]++;
    }
    rep(i,10){rep(j,10){
        ll ans = 0;
        rep(k,10){
            if(cnt[k]==0)continue;
            ll t = calc(k,i,j);
            if(t==-1)ans = -longinf;
            else ans += t*cnt[k];
        }
        if(ans<0)cout<<-1<<" ";
        else cout<<ans<<" ";
    }
    cout<<endl;
    }
    return 0;
}