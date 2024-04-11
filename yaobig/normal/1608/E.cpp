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
template <typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template <typename A> string to_string(A v) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x) {for(;i<=n;i+=i&-i) a[i]+=x;}
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) ans+=a[i];
        return ans;
    }
    T ask(int l,int r) {return ask(r)-ask(l-1);}
    int find(T x) // find the first pos such that ask(pos) >= x.
    {
        int pos=0;
        per(i,0,__lg(n))
        {
            if((pos | (1<<i)) <= n && a[pos | (1<<i)] < x) 
            {
                pos |= 1<<i;
                x -= a[pos];
            }
        }
        return pos+1;
    }
};
BIT<int> cnt[4],all[4],tmp[4];
vi pool[4][maxn+5];

struct node
{
    int x,y,c;
}p[maxn+5];


int main()
{
    int n; scanf("%d",&n);
    vi vy,vx;
    rep(i,1,n)
    {
        int x,y,c; scanf("%d%d%d",&x,&y,&c);
        p[i]=node{x,y,c};
        vy.pb(y);
        vx.pb(x);
    }
    sort(all(vx)); vx.erase(unique(all(vx)),vx.end());
    sort(all(vy)); vy.erase(unique(all(vy)),vy.end());
    rep(i,1,n) 
    {
        p[i].x = lower_bound(all(vx),p[i].x) - vx.begin() + 1;
        p[i].y = lower_bound(all(vy),p[i].y) - vy.begin() + 1;
    }
    auto solve = [&](){
        rep(i,1,3) all[i].init(n);
        rep(c,1,3) rep(i,1,n) pool[c][i].clear();
        rep(i,1,n)
        {
            auto [x,y,c] = p[i];
            all[c].add(y,1);
            pool[c][x].pb(y);
        }
        auto helper = [&](int A,int B,int C,int X) {
            cnt[A] = all[A];
            cnt[B].init(n);
            cnt[C].init(n);
            per(x,1,n) 
            {
                if(cnt[A].ask(1,n)<X) break;
                if(cnt[B].ask(1,n)>=X) 
                {
                    int thr = cnt[A].find(X);
                    int thr2 = cnt[B].find(X);
                    if(all[C].ask(max(thr,thr2)+1,n)>=X) return 1;
                    if(thr2<thr && cnt[C].ask(thr2+1,n)>=X) return 1;
                }
                for(auto y: pool[A][x]) cnt[A].add(y,-1);
                for(auto y: pool[B][x]) cnt[B].add(y,1);
                for(auto y: pool[C][x]) cnt[C].add(y,1);
            }
            return 0;
        };
        auto helper2 = [&](int A,int B,int C,int X) {
            int sa = 0, sb = 0, sc = 0;int ptr = 1;
            while(sa<X && ptr<=n) sa+=sz(pool[A][ptr]), ptr++;
            while(sb<X && ptr<=n) sb+=sz(pool[B][ptr]), ptr++;
            while(sc<X && ptr<=n) sc+=sz(pool[C][ptr]), ptr++;
            if(sc>=X) return 1;
            else return 0;
        };

        auto hel = [&](int A,int B,int C,int X) {
            if(helper(A,B,C,X)) return 1;
            return helper2(A,B,C,X);
        };
        auto check = [&](int C) {
            if(hel(1,2,3,C)) return 1;
            if(hel(1,3,2,C)) return 1;
            if(hel(2,1,3,C)) return 1;
            if(hel(2,3,1,C)) return 1;
            if(hel(3,1,2,C)) return 1;
            if(hel(3,2,1,C)) return 1;
            return 0;
        };

        auto lb = [&](int l,int r) {
            r++;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(check(mid)) l=mid+1;
                else r=mid;
            }
            return r-1;
        };
        int ans = lb(1,n/3);
        return ans;
    };
    int ans = solve();
    rep(i,1,n) swap(p[i].x,p[i].y);
    chmax(ans,solve());
    printf("%d\n",ans*3);
    return 0;
}