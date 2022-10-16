#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
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
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int a[maxn+5];

void work(int n,int l,int r)
{
    puts("YES");
    vi ans;
    auto op=[&](int i) {
        assert(i>1 && i<n);
        ans.pb(i-1);
        int x=a[i-1]^a[i]^a[i+1];
        a[i-1]=a[i]=a[i+1]=x;
    };
    int cnt=0;
    rep(i,1,l-1) cnt+=a[i];
    if(cnt&1)
    {
        while(l!=r)
        {
            op(l);
            l+=2;
        }
        op(l); l--; r++;
    }
    per(i,1,l-1) if(a[i])
    {
        if(a[i-1]) op(i);
        else if(a[i-2]) op(i-1);
        else {op(i-1); op(i);}
    }
    rep(i,r+1,n) if(a[i])
    {
        if(a[i+1]) op(i);
        else if(a[i+2]) op(i+1);
        else {op(i+1); op(i);}
    }
    printf("%d\n",sz(ans));
    rep(i,0,sz(ans)-1) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
}

void solve()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int cnt=0;
    rep(i,1,n) cnt+=a[i];
    if(cnt&1) {puts("NO"); return;}
    int C=0;
    for(int l=1;l<=n;)
    {
        int r=l+1;
        while(r<=n && a[l]==a[r]) r++;
        //debug(l, r);
        if(a[l]==1) C+=r-l;
        else
        {
            if((r-l)&1) {work(n,l,r-1); return;}
            if(C%2==0) {work(n,l,r-1); return;}
        }
        l=r;
    }
    puts("NO");
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--) solve();
    return 0;
}