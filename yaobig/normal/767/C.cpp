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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi e[maxn+5];
int a[maxn+5],sum[maxn+5];

void getsum(int now)
{
    sum[now] = a[now];
    for(auto v: e[now])
    {
        getsum(v);
        sum[now] += sum[v];
    }
}

int main()
{
    int n; scanf("%d",&n);
    int rt = -1;
    rep(i,1,n)
    {
        int fa; scanf("%d%d",&fa,&a[i]);
        if(fa==0) rt = i;
        else e[fa].pb(i);
    }
    getsum(rt);
    int s = sum[rt];
    if(s%3!=0) return puts("-1"),0;
    s /= 3;
    static int ok1[maxn+5],ok2[maxn+5];
    int cnt1 = 0, cnt2 = 0;
    function<void(int)> dfs = [&](int now) {
        if(sum[now]==s)
        {
            if(cnt1) rep(i,1,n) if(ok1[i]) printf("%d %d\n",now,i), exit(0);
            if(cnt2) rep(i,1,n) if(ok2[i]) printf("%d %d\n",now,i), exit(0);
        }
        if(sum[now]==s*2 && now!=rt) ok2[now] = 1, cnt2++;
        for(auto v: e[now]) dfs(v);
        if(sum[now]==s*2 && now!=rt) ok2[now] = 0, cnt2--;
        if(sum[now]==s) ok1[now] = 1, cnt1++;
    };
    dfs(rt);
    puts("-1");
    return 0;
}