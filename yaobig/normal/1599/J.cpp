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

const int maxn = 1000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

const int MAXA = 1000000;
int a[maxn+5];
int cnt[MAXA+5];

int ans[maxn+5];
bitset<13000005> ok[14];

void solve(vi &A)
{   
//for(auto x: A) debug(x);
    int n = sz(A);
    ans[1] = (A[0] + A[1] - A[2])/2;
    ans[2] = A[0] - ans[1];
    ans[3] = A[1] - ans[1];
    rep(i,3,n-1) ans[i+1] = A[i] - ans[1];
    puts("YES");
    rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    exit(0);
}
int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) cnt[a[i]]++;
    rep(i,1,MAXA) if(cnt[i]>1)
    {
        int tot=0;
        rep(i,1,n) if(cnt[a[i]])
        {
            ans[++tot]=a[i];
            cnt[a[i]]=0;
        }
        puts("YES");
        rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
        return 0;
    }
    if(n==2) return puts("NO"),0;
    vi odd,even;
    rep(i,1,n) if(a[i]&1) odd.pb(a[i]); else even.pb(a[i]);
    if(sz(odd)==1)
    {
        if(sz(even)<=2) return puts("NO"),0;
        vi tmp;
        for(auto x: even) tmp.pb(x);
        for(auto x: odd) tmp.pb(x);
        solve(tmp);
    }
    else if(sz(odd)==0) solve(even);
    else if(sz(even))
    {
        vi tmp;
        tmp.pb(even.back()); even.pop_back();
        for(auto x: odd) tmp.pb(x);
        for(auto x: even) tmp.pb(x);
        solve(tmp);
    }
    else
    {
        int nn=min(27,n);
        int N=1<<nn;
        rep(msk,1,N-1) if(__builtin_popcount(msk)<=13) 
        {
            int c = __builtin_popcount(msk);
            int sum=0;
            for(int S = msk; S; S -= S&-S) sum += a[__builtin_ctz(S)+1];
            if(ok[c][sum])
            {
                rep(msk2,1,N-1) if(__builtin_popcount(msk2)==c)
                {
                    int sum2=0;
                    for(int S = msk2; S; S -= S&-S) sum2 += a[__builtin_ctz(S)+1];
                    if(sum2==sum)
                    {
                        vi A,B;
                        rep(i,0,26) if(msk>>i&1) A.pb(a[i+1]),cnt[a[i+1]]=0; 
                        rep(i,0,26) if(msk2>>i&1) B.pb(a[i+1]),cnt[a[i+1]]=0; 
                        vi C;
                        rep(i,0,sz(A)-1) C.pb(A[i]),C.pb(B[i]);
                        int now=0;
                        int tot=0;
                        for(auto x: C)
                        {
                            now = x - now;
                            ans[++tot] = now;
                        } 
                        rep(i,1,n) if(cnt[a[i]]) ans[++tot] = a[i] - now;
                        puts("YES");
                        rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);                            
                        return 0;
                    }
                }
            }
            ok[c].set(sum);
        }

    }
    puts("NO");
    return 0;
}