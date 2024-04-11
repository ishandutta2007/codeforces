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

const int maxn = 200000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,const int &y) {x-=y; if(x<0) x+=mod;}

int a[maxn+5];
int ways[maxn+5],cnt[maxn+5];

template<class T> struct BIT
{
    int n,timer;
    T a[maxn+5];
    int mark[maxn+5];
    void init(int _n)
    {
        n=_n; timer = 0;
        rep(i,1,n) a[i]=0;
    }
    void clear() {timer++;}
    void add(int i,T x) 
    {
        for(;i<=n;i+=i&-i) 
        {
            if(mark[i]!=timer) a[i] = 0, mark[i] = timer;
            chadd(a[i],x);
        }
    }
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) if(mark[i]==timer) chadd(ans,a[i]);
        return ans;
    }
};
BIT<int> A,B;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        static int id[maxn+5],rk[maxn+5];
        rep(i,1,n) id[i] = i;
        sort(id+1,id+n+1,[&](int i,int j){
            if(a[i]!=a[j]) return a[i]<a[j];
            return i>j;
        });
        rep(i,1,n) rk[id[i]] = i;
        A.init(n);
        B.init(n);
        int ans = 0;
        rep(i,1,n)
        {
            int w = A.ask(rk[i]); chadd(w,1); ways[i] = w; A.add(rk[i],w);
            int c = B.ask(rk[i]); chadd(c,w); cnt[i] = c; B.add(rk[i],c);
            chadd(ans,c);
        }
        B.clear();
        int mx = 0;
        per(i,1,n)
        {
            int x = rk[i];
            if(x>mx)
            {
                int y = mx; mx = x;
                rep(j,y+1,x)
                {
                    int pos = id[j];
                    int w = B.ask(pos); chadd(w,ways[pos]); B.add(pos,w);
                    if(j==x) chsub(ans,w);
                }
                B.clear();
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}