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

const int maxn = 500;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct KM
{
    int n;
    ll w[maxn+5][maxn+5],x[maxn+5],y[maxn+5],slack[maxn+5];
    int prev_x[maxn+5],prev_y[maxn+5],link[maxn+5],par[maxn+5];
    void init(int _n)
    {
        n=_n; rep(i,1,n) rep(j,1,n) w[i][j]=-inf;
    }
    void adjust(int v)
    {
        link[v]=prev_y[v];
        if(prev_x[link[v]]!=-2) adjust(prev_x[link[v]]);
    }
    bool find(int v)
    {
        rep(i,1,n) if(prev_y[i]==-1)
        {
            ll t=x[v]+y[i]-w[v][i];
            if(slack[i]>t) slack[i]=t,par[i]=v;
            if(t==0)
            {
                prev_y[i]=v;
                if(link[i]==-1)
                {
                    adjust(i);
                    return 1;
                }
                if(prev_x[link[i]]!=-1) continue; //necessary?
                prev_x[link[i]]=i;
                if(find(link[i])) return 1;
            }
        }
        return 0;
    }
    ll work()
    {
        rep(i,1,n)
        {
            x[i]=-1ll<<60;
            rep(j,1,n) x[i]=max(x[i],w[i][j]);
        }
        rep(i,1,n) y[i]=0,link[i]=-1;
        rep(i,1,n)
        {
            rep(j,1,n) prev_x[j]=prev_y[j]=-1,slack[j]=1ll<<60;
            prev_x[i]=-2;
            if(find(i)) continue;
            bool flag=0;
            while(!flag) // at most N times?
            {
                ll d=1ll<<60;
                rep(j,1,n) if(prev_y[j]==-1) d=min(d,slack[j]);
                rep(j,1,n) if(prev_x[j]!=-1) x[j]-=d;
                rep(j,1,n) if(prev_y[j]!=-1) y[j]+=d; else slack[j]-=d;
                rep(j,1,n) if(prev_y[j]==-1 && slack[j]==0)
                {
                    prev_y[j]=par[j];
                    if(link[j]==-1)
                    {
                        adjust(j); flag=1; break;
                    }
                    prev_x[link[j]]=j;
                    if(find(link[j]))
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
        ll ans=0;
        rep(j,1,n) ans+=w[link[j]][j];
        return ans;
    }
}km;

int main()
{
    int n; scanf("%d",&n);
    km.init(n);
    rep(i,1,n)
    {
        int a,b,k; scanf("%d%d%d",&a,&b,&k);
        rep(j,1,n)
        {
            ll w = a - 1ll*b*min(j-1,k);
            if(w<0) w = 0;
            km.w[i][j] = w;
        }
    }
    ll ans = km.work();
    printf("%lld\n",ans);
    return 0;
}