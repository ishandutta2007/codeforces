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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}


int main()
{
    int cas = 1; scanf("%d",&cas); 
    while(cas--) 
    {
        int n; scanf("%d",&n);
        static map<int,int> M; M.clear();
        rep(i,1,n)
        {
            int x; scanf("%d",&x);
            M[x]++;
        }
        static vector<pii> A; A.clear();
        for(auto [x,c]: M) A.pb({x,c});
        int ans = 0, N = sz(A);
        rep(i,0,N-1)
        {
            auto [x,cnt] = A[i];
            if(i<N-1)
            {
                int delta = A[i+1].FI - x;
                cnt++;
                delta*=2;
                while(delta<=1e9)
                {
                    auto it = lower_bound(all(A),pii{x+delta,-1});
                    if(it==A.end()) break;
                    delta = it->FI - x;
                    cnt++;
                    delta*=2;
                }
            }
            chmax(ans,cnt);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}