#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
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
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MM = 1e5+5, LG=30;
int n, i, j, nim[]={1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14}, vs[MM];
unordered_map<int,int> dp;

int brute(int msk){
    if(!msk) return 0;
    else if(dp.count(msk)) return dp[msk];
    int cur=msk;
    unordered_set<int> mex;
    for(int i=0;i<30;i++){
        cur=msk;
        if(msk&(1<<i)){
            for(int j=i;j<30;j+=i+1){
                if(cur&(1<<j)) cur^=(1<<j);
            }
            mex.insert(brute(cur));
        }
    }
    for(int i=0;;i++){
        if(!mex.count(i)){
            dp[msk]=i;
            return i;
        }
    }
}

int main(){
    /*for(i=1;i<=30;i++){
        int sta=(1<<i)-1;
        printf("%d,",brute(sta));
    }*/
    scanf("%d",&n);
    int one=n, grundy=0;
    for(i=2;i<=min(n,MM-1);i++){
        if(!vs[i]){
            ll x=i;
            for(j=1;x<=n;x*=i,j++){
                if(x<MM) vs[x]=1;
            }
            one-=(j-1);
            grundy^=nim[j-2];
        }
    }
    one&=1;
    printf("%s\n",grundy^one?"Vasya":"Petya");
    return 0;
}