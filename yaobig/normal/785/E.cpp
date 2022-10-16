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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct FenwickSegmentTree
{
    #define MAXN (maxn*130)

    int n,m,tot;
    array<int,MAXN+5> ls,rs,a;
    array<int,maxn+5> rt;
    void init(int _n,int _m)
    {
        rep(i,1,tot) ls[i]=rs[i]=a[i]=0;
        n=_n; m=_m; tot=0;
        rep(i,1,n) rt[i]=0;
    }
    void add(int &i,int l,int r,int pos,int v)
    {
        if(!i) i=++tot;
        a[i]+=v;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(pos<=mid) add(ls[i],l,mid,pos,v);
        else add(rs[i],mid+1,r,pos,v);
    }
    int ask(int i,int l,int r,int ql,int qr)
    {
        if(i==0 || ql>r || l>qr) return 0;
        if(ql<=l && r<=qr) return a[i];
        int mid=(l+r)>>1;
        return ask(ls[i],l,mid,ql,qr)+ask(rs[i],mid+1,r,ql,qr);
    }
    void add(int x,int y,int v) //A[x][y]+=v
    {
        for(;x<=n;x+=x&-x) add(rt[x],1,m,y,v);
    }
    int ask(int x,int l,int r) // return A[1~x][l~r]
    {
        int res=0;
        for(;x;x-=x&-x) res+=ask(rt[x],1,m,l,r);
        return res;
    }
    int rangeask(int x,int y,int l,int r) {return ask(y,l,r)-ask(x-1,l,r);}
    void erase(int x)
    {
        for(;x<=n;x+=x&-x) rt[x]=0;
    }
}T;

int a[maxn+5];

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    T.init(n,n);
    rep(i,1,n) T.add(i,i,1),a[i]=i;
    ll ans=0;
    while(q--)
    {
        int p1,p2; scanf("%d%d",&p1,&p2);
        if(p1>p2) swap(p1,p2);
        if(p1!=p2)
        {
            int &x=a[p1],&y=a[p2];
            ans+=T.rangeask(p1+1,p2-1,1,y-1)*2;
            ans-=T.rangeask(p1+1,p2-1,1,x-1)*2;
            ans+=x<y?1:-1;
            T.add(p1,x,-1);
            T.add(p2,y,-1);
            T.add(p1,y,1);
            T.add(p2,x,1);
            swap(x,y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}