#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
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

const int maxn = 50'000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.length();
    map<string,vi> M;
    rep(l,1,4) rep(i,0,n-l) M[s.substr(i,l)].pb(i);
    
    map<pair<string,string>,int> ans;
    int q; cin >> q;
    while(q--)
    {
        string a,b; cin >> a >> b;
        auto solve = [&](string &a,string &b) {
            if(ans.count(mp(a,b))) return ans[mp(a,b)];
            int res = inf;
            if(M.count(a) && M.count(b))
            {
                if(sz(M[a])>sz(M[b])) swap(a,b);
                vi &A = M[a], &B = M[b];
                for(auto x: A)
                {
                    auto pos = lower_bound(all(B),x) - B.begin();
                    if(pos<sz(B))
                    {
                        int y = B[pos];
                        chmin(res, (int)max(x+a.length(), y+b.length()) - x);
                    }
                    if(pos>0)
                    {
                        int y = B[pos-1];
                        chmin(res, (int)max(x+a.length(), y+b.length()) - y);
                    }
                }
            }
            return ans[mp(a,b)] = ans[mp(b,a)] = res;
        };
        int ans = solve(a,b);
        if(ans==inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}