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
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

string s[maxn+5];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int cas; cin >> cas; while(cas--)
    {
        int n; cin >> n;
        rep(i,1,n) cin >> s[i];
        set<string> S;
        rep(i,1,n) S.insert(s[i]);
        int ok = 0;
        rep(i,1,n) 
        {
            auto t = s[i]; reverse(all(t));
            if(S.count(t)) ok = 1;
        }
        if(ok) puts("YES");
        else
        {
            set<string> T[2];
            rep(i,1,n)
            {
                auto t = s[i];
                reverse(all(t));
                if(sz(t)==3) 
                {
                    t.pop_back();
                    if(T[0].count(t)) ok = 1;
                    s[i].pop_back();
                    T[1].insert(s[i]);
                }
                else
                {
                    if(T[1].count(t)) ok = 1;
                    T[0].insert(s[i]);
                }
            }
            puts(ok ? "YES" : "NO");
        }
    }
    return 0;
}