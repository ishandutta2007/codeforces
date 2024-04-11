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

const int MN = 3e5+5;
int n, k, dp[MN][2], cnt[MN][2], i, j, l;

int main(){
    for(scanf("%d%d",&n,&k),i=1;i<=n;i++)
        scanf("%d",&cnt[i][0]);
    for(i=1;i<=n;i++)
        scanf("%d",&cnt[i][1]);
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i][1]=1<<30;
        for(l=0;l<2;l++){
            if(cnt[i][l]>=cnt[i][!l]){
                int mn=dp[i-1][l];
                int hm=ceil((mn+cnt[i][l])/(double)k);
                if(mn>k||hm-1>cnt[i][!l]) continue;
                if(hm-1<cnt[i][!l]) dp[i][l]=0;
                else dp[i][l]=mn+cnt[i][l]-k*cnt[i][!l];
            }
            else{
                int mn=dp[i-1][!l];
                int hm=ceil((mn+cnt[i][!l])/(double)k);
                if(mn>k||hm-1>cnt[i][l]) continue;
                dp[i][l]=0;
            }
        }
    }
    if(dp[n][0]<=k||dp[n][1]<=k) printf("YES\n");
    else printf("NO\n");
    return 0;
}