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

const int maxn = 50000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int k;
struct node
{
    int mx[10],mn[10],cnt;
    node(int *a)
    { 
        rep(i,0,k-1) mx[i] = mn[i] = a[i];
        cnt = 1; 
    }
};
bool operator <(const node &a,const node &b) 
{
    rep(i,0,k-1) if(a.mx[i]>b.mn[i]) return 0;
    return 1;
}
node& operator +=(node &a,const node &b)
{
    rep(i,0,k-1) 
    {
        chmax(a.mx[i],b.mx[i]);
        chmin(a.mn[i],b.mn[i]);
    }
    a.cnt += b.cnt;
    return a;
}

int main()
{
    int n; scanf("%d%d",&n,&k);
    set<node> S;
    rep(i,1,n)
    {
        static int a[10]; rep(j,0,k-1) scanf("%d",&a[j]);
        node A(a);
        while(S.count(A))
        {
            auto it = S.find(A);
            A += *it;
            S.erase(it);
        }
        S.insert(A);
        printf("%d\n",(--S.end())->cnt);
    }
    return 0;
}