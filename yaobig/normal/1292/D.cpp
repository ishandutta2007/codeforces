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

const int maxn = 5'000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int main()
{
    static int maxp[maxn+5], pcnt[maxn+5]; vi pr;
    rep(i,2,maxn) if(maxp[i]==0) 
    {
        pr.pb(i);
        for(int j=i;j<=maxn;j+=i) maxp[j] = i;
    }
    rep(i,2,maxn) pcnt[i] = pcnt[i/maxp[i]] + 1;
    reverse(all(pr));

    int n; scanf("%d",&n);
    static int cnt[maxn+5], ps[maxn+5];
    rep(i,1,n) {int x; scanf("%d",&x); x += x==0; cnt[x]++;}
    rep(i,1,maxn) ps[i] = ps[i-1] + cnt[i];
    ll ans = 0, pspcnt = 0;
    rep(i,1,maxn) 
    {
        pspcnt += pcnt[i];
        ans += 1ll*pspcnt*cnt[i];
    }
    int l = 1, r = maxn, sum = ps[maxn];
    for(auto p: pr)
    {
        int tot = ps[r]-ps[l-1];
        if(tot*2<=sum) break;
        for(int i=0;i<=r;i+=p)
        {
            int L = max(l,i);
            int R = min(r,i+p-1);
            tot -= L<=R ? ps[R] - ps[L-1] : 0;
            if(tot*2>sum) 
            {
                int now = i+p, c = 0;
                while(now%p==0) now /= p, c++;
                ans -= 1ll*(tot*2-sum)*c;
            }
            else
            {
                l = L; r = R;
                break;
            }
        }
    } 
    printf("%lld\n",ans);
    return 0;
}