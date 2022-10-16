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

const int maxn = 100000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        static char A[maxn+5],B[maxn+5];
        scanf("%s%s",A+1,B+1);
        int ok = 1;
        int has[25][25] = {};
        rep(i,1,n) 
        {
            if(A[i]>B[i]) ok = 0;
            else if(A[i]<B[i]) has[A[i]-'a'+1][B[i]-'a'+1] = 1;
        }
        if(ok==0) puts("-1");
        else
        {
            int ans = 0;
            per(len,2,20) rep(l,1,20-len+1)
            {
                int r = l+len-1;
                if(has[l][r])
                {
                    int ok = 1;
                    int last = r;
                    per(i,l+1,r-1) if(has[l][i]) 
                    {
                        has[i][last] = 1;
                        last = i;
                        ok = 0;
                    }
                    has[l][last] = 1;
                    last = l;
                    rep(i,l+1,r-1) if(has[i][r])
                    {
                        has[last][i] = 1;
                        last = i;
                        ok = 0;
                    }
                    has[last][r] = 1;
                    ans += ok;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}