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

const int MAXA = 7000;
using bs = bitset<MAXA+5>;
bs fac[MAXA+5],rev[MAXA+5],S[maxn+5];
int mu[MAXA+5];

int main()
{
    rep(i,1,MAXA) for(int j=i;j<=MAXA;j+=i) fac[j].set(i);
    rep(i,1,MAXA) mu[i] = 1;
    rep(i,2,MAXA) for(int j=i*i;j<=MAXA;j+=i*i) mu[j] = 0;
    rep(i,1,MAXA) rep(j,1,MAXA/i) if(mu[j]) rev[i].set(i*j); 

    int n,q; scanf("%d%d",&n,&q);
    while(q--)
    {
        int op,x; scanf("%d%d",&op,&x);
        if(op==1)
        {
            int v; scanf("%d",&v);
            S[x] = fac[v];
        }
        else if(op==2)
        {
            int y,z; scanf("%d%d",&y,&z);
            S[x] = S[y] ^ S[z];
        }
        else if(op==3)
        {
            int y,z; scanf("%d%d",&y,&z);
            S[x] = S[y] & S[z];
        }
        else
        {
            int v; scanf("%d",&v);
            printf("%d",(int)(S[x] & rev[v]).count()&1);
        }
    }
    puts("");
    return 0;
}