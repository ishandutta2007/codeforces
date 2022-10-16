 #include "bits/stdc++.h"
#define rep(i, a, n) for(auto i = a; i <= n; i++)
#define per(i, a, n) for(auto i = n; i >= a; i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
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
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }

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

const int maxn = 200;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int cas; scanf("%d", &cas); while(cas--)
    {
        int n; scanf("%d", &n); 
        static int p[maxn + 5], inv[maxn + 5];
        rep(i, 1, n) scanf("%d", &p[i]), inv[p[i]] = i;
        vi mark(n + 1); int tot = 0;
        rep(i, 1, n) if(mark[i] == 0)
        {
            tot++;
            int now = i;
            while(mark[now] == 0) mark[now] = tot, now = p[now];
        }
        vi vis(n + 1), cyc_vis(tot + 1), ans;
        function<void(int)> dfs = [&](int s)
        {
            int X = mark[s];
            cyc_vis[X] = 1;
            int now = s;
            while(vis[now] == 0)
            {
                ans.pb(now);
                vis[now] = 1;
                if(now < n && cyc_vis[mark[now + 1]] == 0) dfs(inv[now + 1]);
                now = inv[now];
            }
        };
        dfs(1);
        rep(i, 1, n) printf("%d%c", ans[i - 1], " \n"[i == n]);
    }
    return 0;
}