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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
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
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[maxn+5];
int b[2][maxn+5];

int main()
{
    int cas = 1; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        static vector<pii> A; A.clear();
        rep(i,0,n-1) 
        {
            scanf("%s",s);
            rep(j,0,m-1) if(s[j]=='1')
            {
                A.pb({j+i,j-i});
            }
        }
        sort(all(A),[](pii &a,pii &b) {
            if(a.FI!=b.FI) return a.FI<b.FI;
            return a.SE>b.SE;
        });
        b[0][0] = b[0][1] = -inf;
        rep(i,1,m) b[0][i] = b[1][i] = inf;
        for(auto [i,x]: A)
        {
            int par = i&1;
            int l = 1, r = m+1;
            while(l<r)
            {
                int mid = (l+r)>>1;
                if(b[par][mid]>=x) r = mid;
                else l = mid+1;
            }
            b[par][r] = x;
        }
        int ans = 0;
        rep(par,0,1) rep(i,1,m) ans += b[par][i]!=inf;
        printf("%d\n",ans);
    }
    return 0;
}