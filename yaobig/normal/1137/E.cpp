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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct P
{
    ll x,y;
    P():x(0),y(0){}
    P(ll a,ll b):x(a),y(b){}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    LL cross(const P &b) const {return (LL)x*b.y-(LL)y*b.x;}
};

P sta[maxn+5];

int main()
{
    int n; int m; scanf("%d%d",&n,&m);
    ll k = 0, b = 0;
    auto eval = [&](P p) {return p.y+k*p.x+b;};

    int top = 0;
    sta[++top] = P(0,0);
    while(m--)
    {
        int op; scanf("%d",&op);
        if(op==1)
        {
            int len; scanf("%d",&len); 
            n += len;
            top = 0; sta[++top] = P(0,0);
            k = b = 0;
        }
        else if(op==2)
        {
            int len; scanf("%d",&len); 
            P now(n,-k*n-b);
            while(top>1 && (now-sta[top]).cross(sta[top]-sta[top-1])>=0) top--;
            sta[++top] = now;
            n += len;
        }
        else 
        {
            int dk,dB; scanf("%d%d",&dB,&dk);
            k += dk;
            b += dB;
        }
        while(top>1 && eval(sta[top])>=eval(sta[top-1])) top--;
        printf("%lld %lld\n",sta[top].x+1,eval(sta[top]));
    }
    return 0;
}