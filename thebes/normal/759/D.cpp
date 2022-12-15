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
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 5005, mod = 1e9+7;
int dp[2][MN], N, i, j, k, nxt[MN][26], hm[26];
string s;

inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}

int main(){
    cin >> N >> s;
    s.insert(s.begin(),' ');
    memset(hm,-1,sizeof(hm));
    for(i=N;i>=1;i--){
        hm[s[i]-'a']=i;
        for(j=0;j<26;j++)
            nxt[i][j]=hm[j];
    }
    for(j=0;j<26;j++)
        nxt[0][j]=hm[j];
    dp[1][0]=1;
    for(i=1;i<=N;i++){
        memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
        for(j=0;j<=N;j++){
            if(!dp[i&1][j]) continue;
            for(k=0;k<26;k++){
                if(nxt[j][k]!=-1) add(dp[(i+1)&1][nxt[j][k]],dp[i&1][j]);
            }
        }
    }
    int ans = 0;
    for(j=0;j<=N;j++)
        add(ans, dp[(N+1)&1][j]);
    printf("%d\n",ans);
    return 0;
}