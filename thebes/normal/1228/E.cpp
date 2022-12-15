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

const int MN = 255, mod = 1e9+7;
int N, K, i, j, k, c[MN][MN], dp[MN][MN], pw[MN]={1}, pw2[MN]={1};

int main(){
    scanf("%d%d",&N,&K);
    c[0][0]=1;
    for(i=1;i<MN;i++){
        c[i][0]=c[i][i]=1;
        for(j=1;j<i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for(i=1;i<MN;i++) pw[i]=1LL*pw[i-1]*K%mod;
    for(i=1;i<MN;i++) pw2[i]=1LL*pw2[i-1]*(K-1)%mod;
    dp[0][0]=1;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            for(k=0;k<j;k++) dp[i][j]=(dp[i][j]+1LL*dp[i-1][k]*pw[k]%mod*c[N-k][j-k]%mod*pw2[N-j])%mod;
            dp[i][j]=(dp[i][j]+1LL*dp[i-1][j]*pw[k]%mod*pw2[N-j]%mod-1LL*dp[i-1][j]*pw2[k]%mod*pw2[N-j]%mod+mod)%mod;
        }
    }
    printf("%d\n",dp[N][N]);
    return 0;
}