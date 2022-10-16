#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) {a = b; return 1;} return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) {a = b; return 1;} return 0; }
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1,c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }
template<class A> string to_string(A v) 
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

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) 
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
// using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
// indices start from 1.
auto hopcroft(int n,int m,vi e[]) // e records edges from Left to Right.
{
    vi match_x(n+5), match_y(m+5); // record the matched vertex for each vertex on both sides.
    
    int ans = 0;
    while(1)
    {
        static vi dx; dx.assign(n+5,0);
        static vi dy; dy.assign(m+5,0);
        bool ok = 0;
        queue<int> q;
        rep(i,1,n) if(match_x[i]==0) q.push(i);
        while(q.size())
        {
            int x = q.front(); q.pop();
            for(auto y: e[x]) if(dy[y]==0)
            {
                dy[y] = dx[x]+1;
                if(match_y[y])
                {
                    dx[match_y[y]] = dy[y]+1;
                    q.push(match_y[y]);
                }
                else ok = 1;
            }
        }
        if(ok==0) break;

        static vector<bool> vis; vis.assign(m+5,0);
        function<int(int)> find = [&](int x) {
            for(auto y: e[x]) if(vis[y]==0 && dy[y]==dx[x]+1)
            {
                vis[y] = 1;
                if(match_y[y]==0 || find(match_y[y]))
                {
                    match_x[x] = y;
                    match_y[y] = x;
                    return 1;
                }
            }
            return 0;
        };
        rep(i,1,n) if(match_x[i]==0 && find(i)) ans++;
    }
    return match_y;
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    vi a(n), bad, S;
    for(auto &x: a) scanf("%d", &x);
    for(auto x: a) if(x * 3ll <= m) S.pb(x); else bad.pb(x);
    static vi e[maxn + 5];
    rep(i, 0, sz(bad) - 1)
    {
        int x = bad[i];
        int gap = m - x * 2;
        if(gap <= 0) return puts("-1"), 0;
        rep(j, 0, sz(S) - 1) if(S[j] <= gap && x % S[j] == 0) e[i + 1].pb(j + 1);
    }
    auto mat = hopcroft(sz(bad), sz(S), e);
    vector<pii> ans;
    int cnt = 0;
    rep(i, 1, sz(S))
    {
        int x = S[i - 1];
        if(mat[i] == 0) ans.pb({x * 2, x * 3});
        else 
        {
            cnt++;
            int j = mat[i];
            int y = bad[j - 1];
            ans.pb({y + x, y * 2 + x});
        }
    }
    if(cnt != sz(bad)) puts("-1");
    else 
    {
        printf("%d\n", sz(ans));
        for(auto [x, y]: ans) printf("%d %d\n", x, y);
    }
    return 0;
}