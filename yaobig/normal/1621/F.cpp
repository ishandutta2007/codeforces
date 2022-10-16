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
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,a,b,c; scanf("%d%d%d%d",&n,&a,&b,&c);
        scanf("%s",s+1);
        vi A{0},one;
        rep(i,1,n) if(s[i]=='1') one.pb(i);
        if(one.empty())
        {
            if(n==1) printf("%d\n",0);
            else printf("%d\n",a);
            continue;
        }
        int ADD = 0, MINUS = 0;
        if(one[0]>1) ADD += one[0]-2, MINUS++;
        if(one.back()<n) ADD += n-1-one.back(), MINUS++;
        if(sz(one)==1)
        {
            if(ADD) printf("%d\n",a);
            else printf("%d\n",0);
            continue;
        }
        rep(i,0,sz(one)-2)
        {
            int l = one[i], r = one[i+1];
            A.pb(r-l-1);
            if(r-l-1>0) ADD += r-l-2, MINUS++;
        }
        sort(all(A));
        int M = sz(A)-1, N = ADD+MINUS;
        ll ans = 0;
        
        auto solve = [&](int cur) {
            int i = 0, j = 0, cnt = 0, sum = 0;
            while(1)
            {
                if(cur==0) i++;
                else j++;
                if(i>N) break;
                if(j>M) break;
                if(cur==1)
                {
                    if(A[j]>0) cnt++;
                    sum += A[j];
                    if(sum>i) break;
                }
                ll tmp = 1ll*b*j;
                int x = i;
                tmp -= 1ll*c*cnt; x -= cnt;
                tmp += 1ll*a*min(ADD,x); x -= min(x,ADD);
                tmp -= 1ll*c*x;
                chmax(ans,tmp);
                cur ^= 1;    
            }
        };
        solve(0);
        solve(1);
        printf("%lld\n",ans);
    }
    return 0;
}