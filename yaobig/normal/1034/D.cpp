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

const int maxn = 300'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vector<pii> pool[maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    set<pii> S{{inf,0}};
    rep(i,1,n)
    {
        int l,r; scanf("%d%d",&l,&r);
        if(l==r) continue;
        auto [pos,ti] = *S.lower_bound({l,0});
        if(pos>l) S.insert({l,ti});
        int last = l;
        while(1)
        {
            auto [pos,ti] = *S.lower_bound({l+1,0});
            if(pos<=r)
            {
                S.erase({pos,ti});
                pool[i].pb({ti, pos-last});
                last = pos;
            }
            else break;
        }
        if(last!=r) pool[i].pb({S.lower_bound({l+1,0})->SE, r-last});
        S.insert({r,i});
    }
    auto check = [&](int x) {
        ll cnt = 0, sum = 0, s = 0; 
        vi ps(n+2,0);
        int ptr = 1;
        rep(r,1,n) 
        {
            for(auto [l,len]: pool[r])
            {
                if(l+1<ptr) s += 1ll*len*(ptr-l-1), ps[ptr] += len, ps[r+1] -= len;
                else ps[l+1] += len, ps[r+1] -= len;
            }
            while(ptr<=n && ps[ptr]>=x) s += ps[ptr++], ps[ptr] += ps[ptr-1];
            cnt += ptr-1;
            sum += s;
        }
        return mp(cnt,sum);
    };
    int l = 1, r = inf;
    while(l<r)
    {
        int mid = (l+r)>>1;
        ll cnt = check(mid).FI;
        if(cnt<k) r = mid;
        else l = mid+1;
    }
    auto [cnt,sum] = check(l);
    sum += 1ll*(k-cnt)*(l-1);
    printf("%lld\n",sum);
    return 0;
}