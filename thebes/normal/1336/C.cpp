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

const int MN = 3003, mod = 998244353;
int n, m, i, j, k, dp[MN][MN][2];
int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}
string s, t;

int main(){
    cin >> s >> t;
    n=s.size(); m=t.size();
    for(i=1;i<=m;i++){
        if(s[0]==t[i-1]){
            dp[1][i][1]=2;
        }
    }
    dp[1][m+1][0]=2;
    for(i=2;i<=n;i++){
        dp[i][m+1][0]=qpow(2,i);
        for(j=1;j<=m;j++){
            for(k=0;k<2;k++){
                int ot=j+i-1;
                if(k){
                    if(s[i-1]==t[j-1]){
                        dp[i][j][k]+=dp[i-1][j+1][k];
                        if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
                    }
                    if(ot<=m&&s[i-1]==t[ot-1]){
                        dp[i][j][k]+=dp[i-1][j][k];
                        if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
                    }
                }
                else{
                    dp[i][j][k]=dp[i-1][j][k];
                    if(ot==m+1) dp[i][j][k]+=dp[i-1][j][1];
                    if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
                    if(s[i-1]==t[j-1]){
                        dp[i][j][k]+=dp[i-1][j+1][k];
                        if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
                    }
                }
            }
        }
    }
    int ans=0;
    for(i=1;i<=n;i++){
        ans=(ans+1LL*dp[i][1][0])%mod;
        if(i>=m) ans=(ans+dp[i][1][1])%mod;
    }
    printf("%d\n",ans);
    return 0;
}