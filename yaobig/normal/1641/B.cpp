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

const int maxn = 700'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        map<int,int> cnt;
        static int a[maxn+5];
        rep(i,1,n) scanf("%d",&a[i]), cnt[a[i]]++;
        int ok = 1;
        for(auto [_,c]: cnt) if(c&1) ok = 0;
        if(ok==0) puts("-1");
        else 
        {
            vector<pii> op;
            vi ans;
            for(int i = n; i>=1; i-=2)
            {
                int id = -1;
                per(j,1,i-1) if(a[j]==a[i]) {id = j; break;}
                //debug(id,);
                if(id==i-1) ans.pb(2);
                else
                {
                    int l = id, r = i-1, x = r-l+1;
                    rep(j,l,r) op.pb({i-1 + j-l, a[j]});
                    ans.pb(2);
                    vi tmp;
                    rep(i,l,r) tmp.pb(a[i]);
                    rep(i,l,r) tmp.pb(a[i]);
                    per(i,l,r) tmp.pb(a[i]);
                    tmp.pop_back();
                    reverse(all(tmp));
                    //debug(l,r,tmp);
                    rep(j,0,sz(tmp)-1) op.pb({l-1+j,tmp[j]});
                    ans.pb(2*(3*x-1));
                    ans.pb(x*2);
                    rep(j,l,r-1) a[j] = a[j+1];
                }
            }
            reverse(all(ans));
            printf("%d\n",sz(op));
            for(auto [x,y]: op) printf("%d %d\n",x,y);
            printf("%d\n",sz(ans));
            rep(i,1,sz(ans)) printf("%d%c",ans[i-1]," \n"[i==sz(ans)]);
        }
    }
    return 0;
}