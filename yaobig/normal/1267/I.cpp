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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int ask(int x,int y)
{
    printf("? %d %d\n",x,y); fflush(stdout);
    char s[5]; scanf("%s",s);
    return s[0]=='<' ? -1 : 1;
}
void finish()
{
    puts("!"); fflush(stdout);
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        vi A,B;
        rep(i,1,n-1) A.pb(i);
        rep(i,n,n+1) B.pb(i);
        auto getmin = [&](vi &a) {
            int id = a[0];
            for(auto x: a) if(x!=id && ask(x,id)==-1) id = x;
            return id;
        };
        auto erasemin = [&](vi &a,vi &b) {
            int mna = getmin(A);
            int mnb = getmin(B);
            int res = ask(mna,mnb);
            if(res==-1)
            {
                auto it = find(all(A),mna);
                A.erase(it);
            }
            else
            {
                auto it = find(all(B),mnb);
                B.erase(it);
            }
            return res;
        };
        rep(i,n+2,n*2)
        {
            auto res = erasemin(A,B);
            res==-1 ? A.pb(i) : B.pb(i);
        }
        erasemin(A,B);
        finish();
    }
    return 0;
}