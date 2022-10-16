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
template <typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5],b[maxn+5];
int ida[maxn+5],idb[maxn+5],rka[maxn+5],rkb[maxn+5];
int ans[maxn+5],vis[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) scanf("%d",&b[i]);
        rep(i,1,n) ida[i]=idb[i]=i;
        sort(ida+1,ida+n+1,[](int i,int j){return a[i]>a[j];});
        sort(idb+1,idb+n+1,[](int i,int j){return b[i]>b[j];});
        rep(i,1,n) rka[ida[i]]=i;
        rep(i,1,n) rkb[idb[i]]=i;
        rep(i,1,n) ans[i]=vis[i]=0;
        queue<int> q;
        auto safepush = [&](int x) {
            if(x && vis[x]==0)
            {
                q.push(x);
                vis[x] = 1;
            }
        };
        safepush(ida[1]);
        safepush(idb[1]);
        while(sz(q))
        {
            int now = q.front(); q.pop();
            ans[now] = 1;
            safepush(ida[rka[now]-1]);
            safepush(idb[rkb[now]-1]);
        }
        rep(i,1,n) printf("%d",ans[i]);
        puts("");
    }
    return 0;
}