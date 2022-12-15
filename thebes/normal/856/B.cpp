#pragma GCC optimize("Ofast")
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
#define F first
#define S second

const int MN = 1e6+6; const ll mod = (1e9+3)*(15485867);
int T, N, i, j, x, dp[2*MN][2], in[2*MN], vs[2*MN], nxt; bitset<2*MN> ok;
string s; ll hsh, hsh2; unordered_map<ll,int> mp;
set<int> adj[2*MN];

void solve(int n){
    if(vs[n]) return;
    vs[n]=1;
    dp[n][0]=0; dp[n][1]=ok[n]?1:0;
    for(auto v : adj[n]){
        solve(v);
        dp[n][0]+=max(dp[v][0],dp[v][1]);
        dp[n][1]+=dp[v][0];
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        mp.clear(); nxt=0;
        for(i=1;i<=N;i++){
            cin >> s; 
            hsh = hsh2 = 0;
            for(j=0;j<s.size();j++){
                if(j) hsh2=(133LL*hsh2+s[j]-'a'+1)%mod;
                hsh=(133LL*hsh+s[j]-'a'+1)%mod;
                if(!mp.count(hsh)){
                    mp[hsh]=++nxt;
                    ok[nxt]=0; in[nxt]=vs[nxt]=0; adj[nxt].clear();
                }
                int id = mp[hsh];
                ok[id]=1;
                if(j){
                    if(!mp.count(hsh2)){
                        mp[hsh2]=++nxt;
                        ok[nxt]=0; in[nxt]=vs[nxt]=0; adj[nxt].clear();
                    }
                    int id2 = mp[hsh2];
                    adj[id2].insert(id);
                    in[id]++;
                }
            }
        }
        int ans=0;
        for(i=1;i<=nxt;i++){
            if(!in[i]){
                solve(i);
                ans+=max(dp[i][0],dp[i][1]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}