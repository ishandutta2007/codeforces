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

const int maxn = 300000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int pos[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,k; scanf("%d%d",&n,&k);
        if(k==n-1 && n==4) puts("-1");
        else
        {
            int F = n-1;
            rep(i,0,n/2-1) pos[i] = pos[F^i] = i;
            int d = __builtin_popcount(F);
            int now = 0;
            per(i,0,d-1)
            {
                if(k>>i&1)
                {
                    if(k==n-1 && i==0) continue;
                    int x = now^(1<<i);
                    swap(pos[now],pos[x]);
                    now = x;
                }
            }
            if(k==n-1) swap(pos[1],pos[2]);
            static int id[maxn+5];
            rep(i,0,n-1) id[i] = i;
            sort(id,id+n,[](int x,int y){return pos[x]<pos[y];});
            ll sum = 0;
            rep(i,0,n/2-1) 
            {
                printf("%d %d\n",id[i*2],id[i*2+1]);
                sum += id[i*2] & id[i*2+1];
            }
            assert(sum==k);
        }
    }
    return 0;
}