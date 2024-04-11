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

int a[maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n)
    {
        static char s[15]; scanf("%s",s);
        a[i] = s[0]=='?' ? inf : atoi(s);
    }
    int ok = 1;
    rep(st,1,k)
    {
        static vi A; A.clear();
        for(int i=st;i<=n;i+=k) A.pb(a[i]);
        int l = 0;
        while(l<sz(A))
        {
            if(A[l]!=inf) {l++; continue;}
            int L = l==0 ? -inf : A[l-1];
            int r = l+1;
            while(r<sz(A) && A[r]==inf) r++;
            int R = r==sz(A) ? inf : A[r];
            int N = r-l;
            if(R-L-1<N) ok = 0;
            int bestU = N/2;
            chmin(bestU,R-1);
            chmax(bestU,L+N);
            rep(i,l,r-1) A[i] = bestU+i-r+1;
            l = r;
        }
        rep(i,0,sz(A)-2) ok &= A[i]<A[i+1];
        int cnt = 0;
        for(int i=st;i<=n;i+=k) a[i] = A[cnt++];
    }
    if(ok==0) puts("Incorrect sequence");
    else rep(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}