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
//const int mod = 998244353;

struct sqrtdecomposition
{
    int B, sz; vi l,r;
    vector<deque<int>> q;
    vector<vi> cnt;
 
    void build(int n,int _sz,const vi &vec)
    {
        sz = _sz; B = (n-1)/sz + 1;
        l.assign(B,inf); 
        r.assign(B,-inf);
        q.resize(B);
        cnt.assign(B,vi(n+1));

        rep(i,0,n-1)
        {
            int id = i/sz;
            chmin(l[id],i);
            chmax(r[id],i);
            q[id].pb(vec[i]);
            cnt[id][vec[i]]++;
        }
    }
    void upd(int ql,int qr)
    {
        int val = q[qr/sz][qr%sz];
        rep(id,ql/sz,qr/sz)
        {
            int L = max(l[id],ql), R = min(r[id],qr);
            int nxt = q[id][R - l[id]];
            if(L==l[id]) q[id].push_front(val);
            else q[id].insert(q[id].begin() + ql%sz, val);
            if(R==r[id]) q[id].pop_back();
            else q[id].erase(q[id].begin() + qr%sz + 1);
            cnt[id][val]++;
            cnt[id][nxt]--;
            val = nxt;
        }
    }
    int ask(int ql,int qr,int c)
    {
        int res = 0;
        rep(id,ql/sz,qr/sz) res += cnt[id][c];
        rep(i,0,ql%sz-1) res -= q[ql/sz][i]==c;
        rep(i,qr%sz+1,sz(q[qr/sz])-1) res -= q[qr/sz][i]==c;
        return res;
    }
}sqd;

int main()
{
    int n; scanf("%d",&n);
    vi a(n);
    for(auto &x: a) scanf("%d",&x);
    sqd.build(n,330,a);
    int lastans = 0;
    int q; scanf("%d",&q); while(q--)
    {
        int op,l,r; scanf("%d%d%d",&op,&l,&r);
        l = (l+lastans-1)%n;
        r = (r+lastans-1)%n;
        if(l>r) swap(l,r);
        if(op==1) sqd.upd(l,r);
        else
        {
            int k; scanf("%d",&k); k = (k+lastans-1)%n+1;
            int ans = sqd.ask(l,r,k);
            lastans = ans;
            printf("%d\n",ans);
        }
    }
    return 0;
}