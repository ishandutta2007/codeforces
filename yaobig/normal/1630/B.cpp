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

int a[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,k; scanf("%d%d",&n,&k);
        static int cnt[maxn+5];
        rep(i,1,n) cnt[i] = 0;
        rep(i,1,n) scanf("%d",&a[i]), cnt[a[i]]++;
        int ans = inf;
        int r = 0, zero = n, one = 0, x = -1, y = -1;
        rep(l,1,n)
        {
            while(r<n && one-zero<k) 
            {
                r++;
                one += cnt[r];
                zero -= cnt[r];
            }
            if(one-zero>=k) 
            {
                if(chmin(ans,r-l)) x = l, y = r;
            }
            one -= cnt[l];
            zero += cnt[l];
        }
        int last = 0;
        //debug(x,y);
        printf("%d %d\n",x,y);
        while(k>1)
        {
            int now = last, c = 0;
            while(1)
            {
                now++;
                if(a[now]>=x && a[now]<=y) c++;
                else c--;
                if(c>0) break;
            }
            printf("%d %d\n",last+1,now);
            last = now;
            k--;
        }
        printf("%d %d\n",last+1,n);
    }
    return 0;
}