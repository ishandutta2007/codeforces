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

const int maxn = 5000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

using bs = bitset<1000>;

bs val[maxn+5][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    map<string,int> id;

    id["?"] = 0;
    val[0][1].set();

    int n,m; cin >> n >> m;
    rep(i,1,n)
    {
        string name, eq, a; cin >> name >> eq >> a;
        id[name] = i;
        if(a[0]=='0' || a[0]=='1') 
        {
            rep(j,0,m-1) if(a[j]=='1') val[i][0].set(j), val[i][1].set(j);
        }
        else
        {
            string op, b; cin >> op >> b;
            int x = id[a], y = id[b];
            rep(j,0,1) 
            {
                if(op=="AND") val[i][j] = val[x][j] & val[y][j];
                else if(op=="OR") val[i][j] = val[x][j] | val[y][j];
                else val[i][j] = val[x][j] ^ val[y][j];
            }
        }
    }
    string mx,mn;
    rep(j,0,m-1)
    {
        int sum[2] = {};
        rep(i,1,n) rep(k,0,1) sum[k] += val[i][k][j]==1;
        if(sum[0]<sum[1]) mx += '1', mn += '0';
        else if(sum[0]>sum[1]) mx += '0', mn += '1';
        else mx += '0', mn += '0';
    }
    cout << mn << endl;
    cout << mx << endl;
    return 0;
}