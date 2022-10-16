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
template <typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x : v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main()
{
    auto output = [&](vector<pii> A) {
        printf("? %d\n",sz(A));
        for(auto [x,y]: A) printf("%d %d ",x,y);
        puts(""); fflush(stdout);
        int res; scanf("%d",&res);
        return res;
    };
    auto ask = [&](int d) {
        vector<pii> A;
        rep(i,1,200) if(i%d==0)
        {
            rep(j,1,200) A.pb({i,j});
        }
        return output(A);
    };
    int S = ask(1);
    int res[9] = {};
    int l = 1, r = 8;
    while(l<r)
    {
        int mid=(l+r)>>1;
        res[mid] = ask(1<<mid);
        if(S == res[mid] * (1<<mid)) l = mid+1;
        else r = mid;
    } 
    int w = abs(S - res[l] * (1<<l)) / (1<<(l-1));
    int h = S / w;
    printf("! %d\n",2*w+2*h-4); fflush(stdout);
    return 0;
}