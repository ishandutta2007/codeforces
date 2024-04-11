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

const int maxn = 200'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

template<class T> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a;
    array<int,maxn*4+5> id;
    void pu(int i) 
    {
        a[i] = max(a[ls],a[rs]);
        if(a[i]==a[ls]) id[i] = id[ls]; // change here if you want the rightist index.
        else id[i] = id[rs];
    }
    void build(int i,int l,int r)
    {
        if(l==r) 
        {
            a[i]=0;
            id[i]=l;
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,const T &x)
    {
        if(ql<=l && r<=qr)
        {
            chmax(a[i],x);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    pair<T,int> ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return pair<T,int>{a[i],id[i]};
        if(qr<l || r<ql) return pair<T,int>{0,-1};
        int mid=(l+r)>>1;
        auto resl = ask(ls,l,mid,ql,qr);
        auto resr = ask(rs,mid+1,r,ql,qr);
        if(resl.FI>=resr.FI) return resl; // change here if you want the rightist index.
        else return resr;
    }
    #undef ls
    #undef rs
};
Segtree<int> seg;

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    set<int> S;
    rep(i,0,n+1) S.insert(i);
    seg.build(1,1,n);
    static int sta[maxn+5];

    rep(i,1,q)
    {
        int op; scanf("%d",&op);
        if(op==0)
        {
            int l,r,x; scanf("%d%d%d",&l,&r,&x);
            if(x==0)
            {
                auto it = S.lower_bound(l);
                while(it!=S.end() && *it<=r)
                {
                    sta[*it] = 1;
                    S.erase(it++);
                }
            }
            else seg.add(1,1,n,r,r,l);
        }
        else
        {
            int pos; scanf("%d",&pos);
            if(sta[pos]) puts("NO");
            else
            {
                auto it = S.find(pos),it2 = it;
                it--; it2++;
                int L = *it;
                int R = *it2;
                int mx = seg.ask(1,1,n,pos,R-1).FI;
                if(mx>L) puts("YES");
                else puts("N/A");
            }
        }
    }
    return 0;
}