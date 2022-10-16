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

struct LinkedList
{
    int pre[maxn+5],nxt[maxn+5];
    void init(int n)
    {
        rep(i,0,n) nxt[i] = i+1, pre[i+1] = i;
    }
    void erase(int pos)
    {
        int L = pre[pos], R = nxt[pos];
        nxt[L] = R;
        pre[R] = L;
    }
}lst;

ll x;
ll rng() 
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

int a[maxn+5],b[maxn+5],c[maxn+5];

int main()
{
    int n,d; scanf("%d%d%lld",&n,&d,&x);
    rep(i,0,n-1) a[i] = i+1;
    rep(i,0,n-1) swap(a[i],a[rng()%(i+1)]);
    rep(i,0,n-1) b[i] = i<d;
    rep(i,0,n-1) swap(b[i],b[rng()%(i+1)]);
    int s = 2*sqrt(n);
    if(d<=s)
    {
        vi A;
        rep(i,0,n-1) if(b[i]) A.pb(i);
        rep(i,0,n-1) for(auto j: A) if(j<=i) chmax(c[i],a[i-j]);
    }
    else
    {
        static int pos[maxn+5];
        rep(i,0,n-1) pos[a[i]] = i;
        lst.init(n);
        per(i,0,n-1)
        {
            for(int num = lst.pre[n+1]; num; num = lst.pre[num])
            {
                int j = pos[num];
                if(b[i-j]) {c[i] = num; break;}
            }
            lst.erase(a[i]);
        }
    }
    rep(i,0,n-1) printf("%d\n",c[i]);
    return 0;
}