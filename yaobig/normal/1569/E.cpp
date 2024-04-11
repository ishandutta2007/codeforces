#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1<<16;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int pw[40];

int main()
{
    int k,base,h; scanf("%d%d%d",&k,&base,&h);
    pw[0]=1;
    rep(i,1,32) pw[i]=1ll*pw[i-1]*base%mod;
    int n=1<<(k-1);
    int N=1<<(n-1);
    auto solve = [&] (int l,int r,map<int,vi> &A,map<int,vi> &B) {
        deque<pii> q;
        vi RK(n);
        rep(msk,0,N-1)
        {
            int hx=0;
            rep(i,l,r) q.pb({i,n+1});
            rep(rd,0,n-2)
            {
                auto [id1, rk1] = q.front(); q.pop_front();
                auto [id2, rk2] = q.front(); q.pop_front();
                if(msk>>rd&1)
                {
                    hx = (hx + 1ll*id1*pw[rk1])%mod;
                    RK[id1-l] = rk1;
                    q.push_back({id2, rk2/2+1});
                }
                else
                {
                    hx = (hx + 1ll*id2*pw[rk2])%mod;
                    RK[id2-l] = rk2;
                    q.push_back({id1, rk1/2+1});
                }
            }
            auto [id, rk] = q.front(); q.pop_front();
            RK[id-l] = rk;
            A[(hx + 1ll*id*pw[rk])%mod] = RK;
            RK[id-l] = rk-1;
            B[(hx + 1ll*id*pw[rk-1])%mod] = RK;
        }
    };
    map<int,vi> LA,LB,RA,RB;
    solve(1,n,LA,LB);
    solve(n+1,n*2,RA,RB);
    for(auto &it: LA) if(RB.count((h-it.FI+mod)%mod))
    {
        for(auto x: it.SE) printf("%d ",x);
        for(auto x: RB[(h-it.FI+mod)%mod]) printf("%d ",x);
        return 0;
    }
    for(auto &it: LB) if(RA.count((h-it.FI+mod)%mod))
    {
        for(auto x: it.SE) printf("%d ",x);
        for(auto x: RA[(h-it.FI+mod)%mod]) printf("%d ",x);
        return 0;
    }
    puts("-1");
    return 0;
}