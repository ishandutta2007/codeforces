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

const int maxn = 100'000;
const int inf = 0x3f3f3f3f;
//const int mod = 998244353;

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n = _n;
        rep(i,1,n) a[i] = 0;
    }
    void add(int i,T x) {for(;i<=n;i+=i&-i) a[i] += x;}
    int find(T x) 
    {
        int pos = 0;
        per(i,0,__lg(n))
        {
            if((pos | (1<<i)) <= n && a[pos | (1<<i)] < x) 
            {
                pos |= 1<<i;
                x -= a[pos];
            }
        }
        return pos + 1;
    }
};
BIT<int> bit;

int main()
{
	int n; scanf("%d",&n);
	static int a[maxn+5], last[maxn+5], nxt[maxn+5];
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) last[i] = inf;
	per(i,1,n) nxt[i] = last[a[i]], last[a[i]] = i;

	static int ans[maxn+5];
	static vi pool[maxn+5];
	rep(i,1,n) pool[1].pb(i);
	bit.init(n);
	rep(i,1,n) if(last[i]<=n) bit.add(last[i],1);
	rep(i,1,n) 
	{
		for(auto x: pool[i])
		{
			int res = bit.find(x+1);
			ans[x]++;
			if(res<=n) pool[res].pb(x);
		}
		bit.add(i,-1);
		if(nxt[i]<=n) bit.add(nxt[i],1);
	}
	rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}