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

int l[maxn+5],r[maxn+5],c[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        int mx = -1, mn = inf;
        int idr = -1,idl = -1, ok = -1;
        rep(i,1,n)
        {
            scanf("%d%d%d",&l[i],&r[i],&c[i]);
            if(chmax(mx,r[i])) idr = i;
            else if(mx==r[i] && c[idr]>c[i]) idr = i;
            if(chmin(mn,l[i])) idl = i;
            else if(mn==l[i] && c[idl]>c[i]) idl = i;
            if(ok!=-1 && (mx!=r[ok] || mn!=l[ok])) ok = -1;
            if((mx==r[i] && mn==l[i]))
            {
                if(ok==-1) ok = i;
                else if(c[ok]>c[i]) ok = i;
            }
            printf("%d\n",min(c[idl]+c[idr],ok==-1?inf*2:c[ok]));
        }
    }
    return 0;
}