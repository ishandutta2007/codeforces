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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

ll qp(ll a,ll k) 
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

struct DS
{
    int cnt[maxn+5][2];
    int flex,dead;
    void init(int n) {flex=n;}
    void add(int id,int pos,int x,int sgn)
    {
        flex-=cnt[id][0]==0 && cnt[id][1]==0;
        dead-=cnt[id][0] && cnt[id][1];
        cnt[id][(pos+x)%2]+=sgn;
        flex+=cnt[id][0]==0 && cnt[id][1]==0;
        dead+=cnt[id][0] && cnt[id][1];
    }
    int cal()
    {
        if(dead) return 0;
        return qp(2,flex);
    }
};
DS row, col, dia;

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    map<pii,int> M;
    row.init(n);
    col.init(m);
    dia.init(1);
    while(k--)
    {
        int x,y,op; scanf("%d%d%d",&x,&y,&op);
        if(M.count({x,y})) 
        {
            row.add(x,y,M[{x,y}],-1);
            col.add(y,x,M[{x,y}],-1);
            dia.add(1,x+y,M[{x,y}],-1);
            M.erase({x,y});
        }
        if(op!=-1)
        {
            M[{x,y}]=op;
            row.add(x,y,op,1);
            col.add(y,x,op,1);
            dia.add(1,x+y,op,1);
        }
        int ans=(row.cal()+col.cal())%mod;
        ans=(ans-dia.cal()+mod)%mod;
        printf("%d\n",ans);
    }
    return 0;
}