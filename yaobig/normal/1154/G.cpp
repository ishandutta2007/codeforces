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

const int maxn = 10000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int np[maxn+5];
pii A[maxn+5];

int main()
{
    rep(i,1,maxn) A[i] = {inf,0};

    int n; scanf("%d",&n);
    ll ans = 1ll<<60;
    int rx = -1, ry = -1;
    rep(i,1,n)
    {
        int x; scanf("%d",&x); 
        if(A[x].SE && chmin(ans,1ll*x)) rx = A[x].SE, ry = i;
        A[x] = {x,i};
    }
    rep(i,2,maxn) if(np[i]==0) 
    {
        per(j,1,maxn/i) 
        {
            np[j*i] = 1;
            if(A[j].SE && A[j*i].SE && chmin(ans,1ll*A[j].FI*A[j*i].FI/j)) rx = A[j].SE, ry = A[j*i].SE;
            chmin(A[j],A[j*i]);
        }
    }
    if(rx>ry) swap(rx,ry);
    printf("%d %d\n",rx,ry);
    return 0;
}