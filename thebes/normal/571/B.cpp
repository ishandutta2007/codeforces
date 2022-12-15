#include <bits/stdc++.h>
#define DEBUG 1
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
    void pr(const S&a,const T&...b){pr(a);if(sizeof...(b))pr(" "),pr(b...);else pr('\n');}
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
/*
const ll MN = 105, mod = 1e9+7;
ll n, i, j, a, b, r, c;
map<ll,pll> cnt[MN], res, ree;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld%lld",&a,&b);
        r = a;
        for(j=2;j*j<=a;j++){
            if(r%j==0){
                c = 0;
                while(r%j==0) c++,r/=j;
                cnt[j].first=c;
            }
        }
        if(r>1) cnt[r].first=1;
        r = b;
        for(j=2;j*j<=b;j++){
            if(r%j==0){
                c = 0;
                while(r%j==0) c++,r/=j;
                cnt[j].second=c;
            }
        }
        if(r>1) cnt[r].second=1;
    }
    res=cnt[1];
    for(i=2;i<=n;i++){
        ll t=-1, r=0, s=0, inf=0, fx=0, ded=0;
        for(auto v : res){
            pll ot = cnt[i][v.first];
            pll c = v.second;
            if(!ot.second&&!c.second){
                if(ot.first!=c.first){ded=1;break;}
            }
            else if(ot.second&&c.second){
                if(fx){
                    if(c.first+c.second*t==ot.first+ot.second*t)
                }
            }
            else{
                if(!c.second) swap(c,ot);
                ll df = (ot.first-c.first)/c.second;
                if(df*c.second!=ot.first-c.first||df<0||(fx&&df!=t)){ded=1;break;}
                else{fx=1;t=df;}
            }
        }
    }
}*/

const ll MN =  3e5+5, MK = 5005;
ll n, k, arr[MN], i, t, a, b, dp[MK][MK], len[MN];
map<ll,ll> ok;
ll solve(ll a,ll b){
    if(!a&&!b) return 0;
    else if(dp[a][b]!=-1) return dp[a][b];
    dp[a][b]=1LL<<60;
    ll n = a*t+b*(t+1);
    if(a) dp[a][b]=min(dp[a][b],solve(a-1,b)+arr[n]-arr[n-t+1]);
    if(b) dp[a][b]=min(dp[a][b],solve(a,b-1)+arr[n]-arr[n-t]);
    return dp[a][b];
}
int main(){
    for(scanf("%lld%lld",&n,&k),i=1;i<=n;i++) scanf("%lld",&arr[i]);
    sort(arr+1,arr+n+1);
    foxr(i,1,n){
        if(i+k>n) len[i]=1;
        else len[i]=len[i+k]+1;
        if(i-k<1) ok[len[i]]++;
    }
    t = ok.begin()->first;
    a = ok[t];
    b = ok[t+1];
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve(a,b));
    return 0;
}