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
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int a[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) scanf("%d",&a[i]);
        int g = 0;
        rep(i,1,m)
        {
            int x; scanf("%d",&x); g = __gcd(x,g);
        }
        static vi A;
        ll S[2] = {};
        rep(st,1,g)
        {
            A.clear();
            for(int i=st; i<=n; i+=g) A.pb(a[i]);
            sort(all(A));
            ll sum = 0;
            for(auto &x: A) sum += x;
            ll mx[2] = {sum,-1ll<<60};
            int cur = 0;
            for(auto &x: A)
            {
                cur ^= 1;
                sum -= 2ll*x;
                chmax(mx[cur],sum);
            }
            S[0] += mx[0];
            S[1] += mx[1];
        }
        printf("%lld\n",max(S[0],S[1]));
    }
    return 0;
}