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

const int maxn = 100'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    set<int> pos;
    multiset<int> dis;
    auto add = [&](int x) {
        auto it = pos.insert(x).FI;
        if(it!=pos.begin()) dis.insert(x - *prev(it));
        if(it!=--pos.end()) dis.insert(*next(it) - x); 
        if(it!=pos.begin() && it!=--pos.end()) dis.erase(dis.find(*next(it) - *prev(it)));
    };
    auto del = [&](int x) {
        auto it = pos.find(x);
        if(it!=pos.begin()) dis.erase(dis.find(x - *prev(it)));
        if(it!=--pos.end()) dis.erase(dis.find(*next(it) - x)); 
        if(it!=pos.begin() && it!=--pos.end()) dis.insert(*next(it) - *prev(it));
        pos.erase(x);
    };
    auto ask = [&]() {return sz(pos)<=1 ? 0 : *--pos.end() - *pos.begin() - *--dis.end();};
    rep(i,1,n)
    {
        int x; scanf("%d",&x); add(x);
    }
    printf("%d\n",ask());
    while(q--)
    {
        int op,x; scanf("%d%d",&op,&x);
        op==0 ? del(x) : add(x);
        printf("%d\n",ask());
    }
    return 0;
}