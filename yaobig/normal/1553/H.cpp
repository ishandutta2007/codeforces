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

const int maxn = 1<<19;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int cnt[maxn];
struct trie
{
    #define ls LS[i]
    #define rs RS[i]
    array<int,maxn*2> ans,mx,mn,LS,RS;
    void pu(int i,int l,int r)
    {
        int len = r-l+1;
        ans[i] = min(ans[ls],ans[rs]);
        chmin(ans[i], mn[rs] + len/2 - mx[ls]);
        mn[i] = min(mn[ls], mn[rs] + len/2);
        mx[i] = max(mx[ls], mx[rs] + len/2);
    }
    void build(int i,int l,int r)
    {
        if(l==r)
        {
            ans[i] = inf;
            mx[i] = cnt[l] ? 0 : -inf;
            mn[i] = cnt[l] ? 0 : inf;
        }
        else
        {
            int mid=(l+r)>>1;
            LS[i] = i*2;
            RS[i] = i*2+1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i,l,r);
        }
        //debug(i, l, r, ans[i], mn[i], mx[i]);
    }
    void rebuild(int i,int l,int r,int dep,int d)
    {
        if(dep<d) 
        {
            int mid=(l+r)>>1;
            rebuild(ls,l,mid,dep+1,d);
            rebuild(rs,mid+1,r,dep+1,d);
        }
        else if(dep==d) swap(ls,rs);
        pu(i,l,r);
    }
}tr;

int ans[maxn];


int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n)
    {
        int x; scanf("%d",&x); cnt[x]++;
    }
    int N = 1<<k;
    tr.build(1,0,N-1);
    int now = 0;
    ans[now] = tr.ans[1];
    rep(i,1,N-1)
    {
        int d = __builtin_ctz(i);
        now ^= 1<<(k-d-1);
        //debug(now, d);
        tr.rebuild(1,0,N-1,0,d);
        ans[now] = tr.ans[1];
    }
    rep(i,0,N-1) printf("%d%c",ans[i]," \n"[i==N-1]);
    return 0;
}