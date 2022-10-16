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
template <typename A> string to_string(A v) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5];

bool solve()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int L = -1;
    rep(i,1,n) if(a[i]!=a[n+1-i]) {L = i; break;}
    if(L==-1) return 1;
    int R = n+1-L;
    auto helper = [&](int l,int r,int ban) {
        while(l<=r)
        {
            while(l<=r && a[l]==ban) l++;
            while(l<=r && a[r]==ban) r--;
            if(l>r) return 1;
            if(a[l]!=a[r]) return 0;
            else l++, r--;
        }
        return 1;
    };
    if(helper(L,R,a[L]) || helper(L,R,a[R])) return 1;
    else return 0;
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--) puts(solve()?"YES":"NO");
    return 0;
}