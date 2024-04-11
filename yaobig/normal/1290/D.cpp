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

int ask(int x)
{
    printf("? %d\n",x); fflush(stdout);
    char s[5]; scanf("%s",s);
    return s[0]=='Y';
}
void clear() {puts("R"); fflush(stdout);}
void answer(int ans) {printf("! %d\n",ans); fflush(stdout);}

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    vi dead(n+1);
    int sz = k==1 ? 1 : k/2, N = n/sz;
    rep(st,1,N)
    {
        rep(stepsz,st,N-st) 
        {
            clear();
            for(int i=st;i<=N;i+=stepsz) rep(j,(i-1)*sz+1,i*sz) if(ask(j)) dead[j] = 1;
        }
    }
    int ans = 0;
    rep(i,1,n) ans += dead[i]==0;
    answer(ans);
    return 0;
}