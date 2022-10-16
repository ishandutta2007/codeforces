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

const int maxn = 100050;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

using bs = bitset<1<<12>;

int a[12][maxn+5];
vi id[maxn+5];
bs S[maxn+5];

int main()
{
    int n,k,q; scanf("%d%d%d",&n,&k,&q);
    rep(i,0,k-1) rep(j,0,n-1) scanf("%d",&a[i][j]);
    rep(i,0,n-1)
    {
        id[i].resize(k);
        rep(j,0,k-1) id[i][j] = j;
        sort(all(id[i]),[&](int x,int y) {return a[x][i]>a[y][i];});
    }
    int N = 1<<k;
    rep(i,0,k-1) rep(msk,0,N-1) if(msk>>i&1) S[i].set(msk);
    int tot = k-1;
    while(q--)
    {
        int op,x,y; scanf("%d%d%d",&op,&x,&y); x--; y--;
        if(op==1) S[++tot] = S[x] | S[y];
        else if(op==2) S[++tot] = S[x] & S[y];
        else 
        {
            int ans = -1, msk = 0;
            for(auto i: id[y])
            {
                msk |= 1<<i;
                if(S[x][msk]) {ans = a[i][y]; break;}
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}