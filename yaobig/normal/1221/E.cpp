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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;


int main()
{
    auto solve = []() {
        int a,b; scanf("%d%d",&a,&b);
        static char s[maxn+5];
        scanf("%s",s+1);
        int n = strlen(s+1)+1; s[n] = 'X';
        static vi L; L.clear();
        int len = 0, x = 0, y = 0;
        rep(i,1,n) 
        {
            if(s[i]=='X')
            {
                if(len>=b*2) L.pb(len);
                else if(len>=a) y++;
                else if(len>=b) x++;
                len = 0;
            }
            else len++;
        }
        if(x || sz(L)>1) return 0;
        if(sz(L)==0) return y&1;
        int z = L[0];
        if(z<a) return 0;
        z -= a;
        auto check = [&](int l) { return (l>=b && l<a) || (l>=b*2);};
        rep(i,0,z)
        {
            int j = z-i;
            if(check(i) || check(j)) continue;
            int tmp = y + (i>=a) + (j>=a);
            if(tmp%2==0) return 1;
        }
        return 0;
    };
    int cas; scanf("%d",&cas); while(cas--) puts(solve() ? "YES": "NO");
    return 0;
}