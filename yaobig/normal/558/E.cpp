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

template<class T> struct sqrtdecomposition
{
    int N;
    vi l,r;
    array<T,maxn+5> a;
    using ar = array<int,26>;
    vector<ar> cnt;
    vi lz;

    void build(int L,int R,int sz,const vector<T> &vec)
    {
        N = (R-L)/sz + 1;
        l.assign(N+1,inf); 
        r.assign(N+1,-inf);
        cnt.assign(N+1,ar{});
        lz.assign(N+1,0);

        rep(i,L,R) 
        {
            int id = (i-L)/sz +1;
            chmin(l[id],i);
            chmax(r[id],i);
            a[i] = vec[i];
            cnt[id][a[i]]++;
        }
    }
    void pd(int id)
    {
        if(lz[id])
        {
            static vi vec; vec.clear();
            rep(i,0,25) rep(_,1,cnt[id][i]) vec.pb(i);
            if(lz[id]==-1) reverse(all(vec));
            rep(i,l[id],r[id]) a[i] = vec[i-l[id]];
            
            lz[id] = 0;
        }
    }
    void upd(int ql,int qr,int dir)
    {
        ar tmp{};
        rep(id,1,N)
        {
            if(qr<l[id] || r[id]<ql) continue;
            if(ql<=l[id] && r[id]<=qr)
            {
                rep(i,0,25) tmp[i] += cnt[id][i];
            }
            else
            {
                pd(id);
                rep(i,max(l[id],ql),min(r[id],qr)) tmp[a[i]]++;
            }
        }
        vector<pii> vec;
        rep(i,0,25) if(tmp[i]) vec.pb({i,tmp[i]});
        if(dir==1) reverse(all(vec));

        auto get = [&](int x) {
            while(vec.back().SE==0) vec.pop_back();
            int mn = min(vec.back().SE,x);
            vec.back().SE -= mn;
            return pii{vec.back().FI,mn};
        };

        rep(id,1,N)
        {
            if(qr<l[id] || r[id]<ql) continue;
            if(ql<=l[id] && r[id]<=qr)
            {
                cnt[id] = ar{};
                int rem = r[id]-l[id]+1;
                while(rem)
                {
                    auto [c,mn] = get(rem);
                    cnt[id][c] += mn;
                    rem -= mn;
                }
                lz[id] = dir;
            }
            else
            {
                rep(i,max(l[id],ql),min(r[id],qr)) a[i] = get(1).FI;
                cnt[id] = ar{};
                rep(i,l[id],r[id]) cnt[id][a[i]]++;
            }
        }
    }
    vector<T> get(int L,int R)
    {
        rep(id,1,N) pd(id);
        vector<T> res(R+1);
        rep(i,L,R) res[i] = a[i];
        return res;
    }
};

sqrtdecomposition<int> sqd;

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    static char s[maxn+5]; scanf("%s",s+1);
    vi a(n+1);
    rep(i,1,n) a[i] = s[i]-'a';
    sqd.build(1,n,1000,a);
    while(q--)
    {
        int l,r,k; scanf("%d%d%d",&l,&r,&k);
        sqd.upd(l,r,k==1 ? 1 : -1);
    }
    a = sqd.get(1,n);
    rep(i,1,n) printf("%c%s",'a'+a[i],i==n ? "\n" : "");
    return 0;
}