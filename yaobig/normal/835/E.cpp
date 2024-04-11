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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int ask(vi A)
{
    printf("? %d",sz(A));
    for(auto x: A) printf(" %d",x);
    puts("");
    fflush(stdout);
    int res; scanf("%d",&res);
    return res;
}

void answer(int a,int b)
{
    if(a>b) swap(a,b);
    printf("! %d %d\n",a,b);
    fflush(stdout);
    return;
}

int main()
{
    int n,x,y; scanf("%d%d%d",&n,&x,&y);
    int b = 0;
    vi A;
    rep(dig,0,9) 
    {
        vi tmp;
        rep(i,1,n) if(i>>dig&1) tmp.pb(i);
        if(sz(tmp))
        {
            int res = ask(tmp);
            if(res!=x && res!=0) b ^= 1<<dig, A = tmp;
        }
    }
    auto solve = [&](vi a) {
        int l = 0, r = sz(a)-1;
        while(l<r)
        {
            int mid = (l+r)>>1;
            int res = ask(vi(a.begin(),a.begin()+mid+1));
            if(res!=x && res!=0) r = mid;
            else l = mid+1;
        }
        return a[r];
    };
    int res = solve(A);
    answer(res,res^b);
    return 0;
}