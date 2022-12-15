#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

namespace output{
    void pr(short x){cout<<x;}
    void pr(unsigned x){cout<<x;}
    void pr(int x){cout<<x;}
    void pr(long long x){cout<<x;}
    void pr(unsigned long long x){cout<<x;}
    void pr(double x){cout<<x;}
    void pr(long double x){cout<<x;}
    void pr(char x){cout<<x;}
    void pr(const char*x){cout<<x;}
    void pr(const string&x){cout<<x;}
    void pr(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void pr(const pair<S,T>&x){pr(DEBUG?"(":""),pr(x.first),pr(DEBUG?", ":" "),pr(x.second),pr(DEBUG?")":"");}
    template<class T>
    void pr(const vector<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class T>
    void pr(const set<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class T>
    void pr(const multiset<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class S,class T>
    void pr(const map<S,T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class S,class... T>
    void pr(const S&a,const T&...b){pr(a);if(sizeof...(b))pr(" "),pr(b...);else pr("\n");}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const ll MN = 1e6+6, inf = 1LL<<60;
ll n, a, b, arr[MN], dp[MN][3], i, j, ans;

ll chk(ll p,ll s,ll e){
    for(ll j=0;j<3;j++) dp[s-1][j]=0;
    for(ll i=s;i<=e;i++){
        for(ll j=0;j<3;j++) dp[i][j]=inf;
        ll k = arr[i]/p, t = k*p;
        dp[i][1]=min(dp[i-1][1],dp[i-1][0])+a;
        if(t==arr[i]){
            dp[i][2]=min(dp[i-1][2],dp[i-1][1]);
            dp[i][0]=dp[i-1][0];
        }
        else if(t==arr[i]-1||t+p==arr[i]+1){
            dp[i][2]=min(dp[i-1][2],dp[i-1][1])+b;
            dp[i][0]=dp[i-1][0]+b;
        }
    }
    ll res=inf;
    for(ll j=0;j<3;j++) res=min(res,dp[e][j]);
    return res;
}

ll go(ll t,ll s,ll e){
    if(t<=1) return inf;
    ll r = t, res = inf;
    for(ll i=2;i*i<=t;i++){
        if(r%i==0){
            while(r%i==0) r/=i;
            res=min(res,chk(i,s,e));
        }
    }
    if(r!=1) res=min(res,chk(r,s,e));
    return res;
}

int main(){
    scanf("%lld%lld%lld",&n,&a,&b);
    ans = inf;
    for(i=1;i<=n;i++) scanf("%lld",&arr[i]);
    if(n==1) pr(arr[1]>1?0:b);
    else{
        for(i=-1;i<=1;i++){
            ans = min(ans,go(arr[1]+i,2,n)+abs(i)*b);
            ans = min(ans,go(arr[n]+i,1,n-1)+abs(i)*b);
        }
        pr(ans);
    }
    return 0;
}