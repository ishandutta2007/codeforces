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

const int maxn = 2000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int p[maxn+5],s[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&p[i]);
    rep(i,1,n) scanf("%d",&s[i]);
    static int id[maxn+5];
    rep(i,1,n) id[s[i]] = i;
    rep(i,1,n) p[i] = id[p[i]];
    int sum = 0;
    vector<pii> ans;
    rep(i,1,n)
    {
        int x = -1;
        rep(j,i,n) if(p[j]==i) {x = j; break;}
        sum += x-i;
        per(j,i,x-1) if(p[j]>=x) 
        {
            swap(p[j],p[x]);
            ans.pb({j,x});
            x = j;
        }
    }
    printf("%d\n%d\n",sum,sz(ans));
    for(auto [x,y]: ans) printf("%d %d\n",x,y);
    return 0;
}