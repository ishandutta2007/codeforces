#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 1e6+6, mod = 1e9+7;
ll t, n, p, i, arr[MN], dif, pw, fl;
ll qpow(ll b,ll exp){
    if(exp<=0) return 1;
    else if(exp&1){
        ll res=b*qpow(b,exp-1);
        if(res>=mod) fl=1;
        return res%mod;
    }
    else{
        ll res=qpow(b,exp>>1);
        res*=res;
        if(res>=mod) fl=1;
        return res%mod;
    }
}

int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&p);
        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        if(p==1){
            printf("%lld\n",n&1);
            continue;
        }
        sort(arr+1,arr+n+1,[](ll i,ll j){return i>j;});
        dif=0; pw=1e6+65; fl=0; int ded=0;
        for(i=1;i<=n;i++){
            dif=dif*qpow(p,pw-arr[i]);
            pw=arr[i];
            if(dif>=mod||(dif&&fl)) ded=1;
            else if(fl) fl=0;
            dif%=mod;
            if(dif>=1||ded) dif=(dif+mod-1)%mod;
            else dif=(dif+1)%mod;
        }
        dif=dif*qpow(p,pw)%mod;
        printf("%lld\n",dif);
    }
    return 0;
}