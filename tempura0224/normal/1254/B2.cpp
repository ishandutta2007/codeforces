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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    ll sum = 0;
    rep(i,n)sum+=a[i];
    if(sum==1){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll> p;
    ll tmp = sum;
    REP(i,2,1000000){
        if(tmp%i==0){
            p.push_back(i);
            while(tmp%i==0)tmp/=i;
        }
    }
    if(tmp>1)p.push_back(tmp);
    ll ans = longinf;
    for(auto e:p){
        vector<ll> c(n);
        rep(i,n)c[i]=a[i]%e;
        ll res = 0;
        ll s = 0;
        rep(i,n)s += c[i];
        ll cnt = s/e;
        int r=0;
        rep(i,cnt){
            ll pre = 0, ps = 0;
            while(r<n&&pre+c[r]<=(e/2)){
                pre += c[r];
                ps += c[r]*r;
                 ++r;
            }
            ps += ((e/2)-pre)*r;
            if(r<n)c[r]-=e/2-pre;
            res += (e/2)*r-ps;
            ll t = r;
            pre=0, ps = 0;
            while(r<n&&pre+c[r]<=(e+1)/2){
                pre += c[r];
                ps += c[r]*r;
                 ++r;
            }
            ps += ((e+1)/2-pre)*r;
            if(r<n)c[r]-=(e+1)/2-pre;
            res += ps-(e+1)/2*t;
        }
        ans = min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}