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
string to_string(bool b) {return (b ? "true" : "false");}
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

const int maxn = 100'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

struct LinkedList
{
    int pre[maxn+5],nxt[maxn+5];
    void init(int n)
    {
        rep(i,0,n-1) nxt[i] = (i+1)%n, pre[(i+1)%n] = i;
    }
    void erase(int pos)
    {
        int L = pre[pos], R = nxt[pos];
        nxt[L] = R;
        pre[R] = L;
    }
}lst;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        vi a(n);
        for(auto &x: a) scanf("%d",&x);
        queue<pii> q;
        rep(i,0,n-1) if(__gcd(a[i],a[(i+1)%n])==1) q.push({i,(i+1)%n});
        lst.init(n);
        vi vec;
        while(sz(q))
        {
            auto [i,j] = q.front(); q.pop();
            lst.erase(j); vec.pb(j);
            if(sz(q) && q.front().FI==j) q.pop();
            if(sz(vec)<n)
            {
                int nj = lst.nxt[i];
                if(__gcd(a[i],a[nj])==1) q.push({i,nj});
            }
        }
        printf("%d ",sz(vec));
        for(auto x: vec) printf("%d ",x+1);
        puts("");
    }
    return 0;
}