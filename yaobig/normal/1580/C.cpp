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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int x[maxn+5],y[maxn+5],q[maxn+5];
int last[maxn+5];
int ans[maxn+5];
int tmp[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
    rep(i,1,m)
    {
        int op,x; scanf("%d%d",&op,&x);
        q[i]=x;
    }
    int B=300;
    auto add=[](int id,int L,int R) {
        for(int p=L+x[id];p<R;p+=x[id]+y[id])
        {
            ans[p]++;
            ans[min(p+y[id],R)]--;
        }
    };
    rep(i,1,m)  
    {
        int &id=q[i];
        if(x[id]+y[id]>B)
        {
            if(last[id]==0) last[id]=i;
            else 
            {
                add(id,last[id],i);
                last[id]=0;
            }
        }
    }
    rep(id,1,n) if(last[id]) add(id,last[id],m+1);
    rep(i,1,m) ans[i]+=ans[i-1];
    rep(len,2,B)
    {
        rep(i,0,len-1) tmp[i]=0;
        rep(i,1,m) 
        {
            int &id=q[i];
            //debug(len, i, id);
            if(x[id]+y[id]==len)
            {
                if(last[id]==0)
                {
                    last[id]=i;
                    rep(p,last[id]+x[id],last[id]+len-1) tmp[p%len]++;
                }
                else 
                {
                    rep(p,last[id]+x[id],last[id]+len-1) tmp[p%len]--;
                    last[id]=0;
                }
                //debug(i);
                //rep(i,0,len-1) debug(tmp[i]);
            }
            ans[i]+=tmp[i%len];
            //debug(len, i, tmp[i%len]);
        }
    }
    rep(i,1,m) printf("%d\n",ans[i]);
    return 0;
}