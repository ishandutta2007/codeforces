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
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[maxn+5];

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    auto check = [&](int pos) {return s[pos]=='a' && s[pos+1]=='b' && s[pos+2]=='c';};
    int cnt = 0;
    rep(i,1,n-2) cnt += check(i);
    while(q--)
    {
        int x; char t[5]; scanf("%d%s",&x,t);
        rep(i,0,2) 
        {
            if(x-i>=1 && x-i<=n-2) cnt -= check(x-i);
        }
        s[x] = t[0];
        rep(i,0,2) 
        {
            if(x-i>=1 && x-i<=n-2) cnt += check(x-i);
        }
        printf("%d\n",cnt);
    }
    return 0;
}