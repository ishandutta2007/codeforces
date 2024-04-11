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

const int maxn = 1'000'000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,c; scanf("%d%d",&n,&c);
        static vi cnt; cnt.assign(c+5,0);
        static vi ps; ps.assign(c+5,0);
        rep(i,1,n)
        {
            int x; scanf("%d",&x); cnt[x] = 1;
        }
        rep(i,1,c) ps[i] += ps[i-1] + cnt[i];
        if(cnt[1]==0) puts("No");
        else
        {
            int ok = 1;
            rep(i,2,c) if(cnt[i]) for(int l=i;l<=c;l+=i)
            {
                int r = min(c,l+i-1);
                if(ps[r]-ps[l-1]>0 && cnt[l/i]==0) ok = 0;
            }
            puts(ok ? "Yes" : "No");
        }
    }
    return 0;
}