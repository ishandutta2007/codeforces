#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5;
int n, i, j; ll arr[MN], ans, tmp;
mt19937 mt(time(0));
int rng(int l,int r){return (mt()%(r-l+1))+l;}
vl go;

void calc(int v){
    //for(auto v : go){
        tmp = 0;
        for(i=1;i<=n;i++){
            if(arr[i]<=v) tmp+=(v-arr[i]%v)%v;
            else tmp+=min(v-arr[i]%v,arr[i]%v);
        }
        ans = min(ans, tmp);
    //}
}

void fac(ll x){
    ll m = x;
    for(ll i=2;i*i<=x;i++){
        if(m%i==0){
            while(m%i==0) m/=i;
            //calc(i);
            tmp = 0;
            for(j=1;j<=n;j++){
                if(arr[j]<=i) tmp+=(i-arr[j]%i)%i;
                else tmp+=min(i-arr[j]%i,arr[j]%i);
            }
            ans=min(ans,tmp);
        }
    }
    if(m!=1){
        tmp = 0;
        for(j=1;j<=n;j++){
            if(arr[j]<=m) tmp+=(m-arr[j]%m)%m;
            else tmp+=min(m-arr[j]%m,arr[j]%m);
        }
        ans=min(ans,tmp);
    }
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }
    for(i=1;i<=n;i++){
        if(arr[i]&1) ans++;
    }
    int steps = 20;
    while(steps--){
        int idx = rng(1,n);
        ll ref = arr[idx];
        if(ref!=1){
            fac(arr[idx]);
            fac(arr[idx]-1);
        }
        fac(arr[idx]+1);
    }
    /*sort(go.begin(),go.end());
    go.erase(unique(go.begin(),go.end()),go.end());*/
    
    printf("%lld\n",ans);
    return 0;
}