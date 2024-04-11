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
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int c[maxn+5],w[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&c[i]);
    rep(i,1,n) scanf("%d",&w[i]);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    ll ans = 0;
    rep(i,1,n)
    {
        if(c[i]%100!=0)
        {
            m += 100-c[i]%100;
            int cost = (100-c[i]%100) * w[i];
            q.push({cost,i});
            if(m>=100) m-=100;
            else 
            {
                ans += q.top().FI; 
                q.pop();
            }
        }
    }
    printf("%lld\n",ans);
    static int pay[maxn+5];
    while(sz(q))
    {
        auto [_,i] = q.top(); pay[i] = 1; q.pop();
    }
    rep(i,1,n)
    {
        if(pay[i]==0) printf("%d %d\n",(c[i]+99)/100,0);
        else printf("%d %d\n",c[i]/100,c[i]%100);
    }
    return 0;
}