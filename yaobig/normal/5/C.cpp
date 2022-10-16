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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[maxn+5];
int ps[maxn+5];
int last[maxn+5],front[maxn+5];

int main()
{
    scanf("%s",s+1);
    int n = strlen(s+1);
    rep(i,1,n) ps[i] = ps[i-1] + (s[i]=='(' ? 1 : -1);
    int mn = *min_element(ps,ps+n+1);
    rep(i,0,n) ps[i] -= mn;
    rep(i,0,n) last[i] = front[i] = -1;
    int ans = 0, cnt = 1;
    last[ps[0]] = front[ps[0]] = 0;
    rep(i,1,n)
    {
        int x = ps[i];
        if(x && last[x-1]!=-1)
        {
            int l = i-last[x-1]-1;
            if(chmax(ans,l)) cnt = 1;
            else if(l && ans==l) cnt++;
        }
        else if(front[x]!=-1)
        {
            int l = i-front[x];
            if(chmax(ans,l)) cnt = 1;
            else if(ans==l) cnt++;
        }
        if(front[x]==-1) front[x] = i;
        last[x] = i;
    }
    printf("%d %d\n",ans,cnt);
    return 0;
}