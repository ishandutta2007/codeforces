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
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct LinearSieve
{
    vi prime;
    bool np[maxn+5];
    void init(int n)
    {
        prime.clear();
        rep(i,2,n)
        {
            if(np[i]==0) prime.pb(i);
            for(auto p: prime)
            {
                ll v=1ll*i*p;
                if(v>n) break;
                np[v]=1;
                if(i%p==0) break;
            }
        }
    }
}sieve;

int id[maxn+5];
int x[maxn+5],y[maxn+5],lp[maxn+5];

int main()
{
    srand(time(0));
    sieve.init(maxn);
    auto &P = sieve.prime;

    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        auto ask = [&](int x,int y)
        {
            printf("? %d %d\n",x,y);
            fflush(stdout);
            ll L; scanf("%lld",&L);
            return L;
        };
        if(n<100)
        {
            map<pii,ll> M;
            rep(i,1,n) rep(j,i+1,n) M[{i,j}] = M[{j,i}] = ask(i,j);
            vector<ll> ans(n+1);
            rep(i,1,n) rep(j,1,n) if(i!=j) ans[i] = __gcd(ans[i],M[{i,j}]);
            if(n==3 && *max_element(ans.begin()+1,ans.end()) - *min_element(ans.begin()+1,ans.end())>=3)
            {
                ll mx = 0;
                rep(i,1,n) chmax(mx, ans[i]);
                rep(i,1,n) if(ans[i]==mx) ans[i] /= 2;
            }

            printf("! ");
            rep(i,1,n) printf("%lld%c",ans[i]," \n"[i==n]);
            fflush(stdout);
        }
        else
        {
            rep(i,1,n) id[i]=i;
            random_shuffle(id+1,id+n+1);
            int tot = 0;
            for(int i=1;i<=n && tot<5000;i+=2)
            {
                x[++tot] = id[i]; 
                y[tot] = i<n ? id[i+1] : id[i-1];
                auto L = ask(x[tot],y[tot]);
                int mx=0;
                for(auto &p: P) if(L%p==0) mx=p;
                lp[tot]=mx;
            }
            int I=0, mx=0;
            I = max_element(lp+1,lp+tot+1) - lp;
            int a = x[I], b = y[I], p = lp[I];
            int c = 0;
            rep(i,1,n) if(i!=a && i!=b) {c = i; break;}
            ll res = ask(a,c);
            int pos = res%p==0 ? a : b;
            vector<ll> ans(n+1);
            assert(pos>=1 && pos<=n);
            ans[pos] = p;
            rep(i,1,n) if(i!=pos)
            {
                ll res = ask(i, pos);
                assert(res % p == 0 && res);
                ans[i] = res / p;
            }
            printf("! ");
            rep(i,1,n) printf("%lld%c",ans[i]," \n"[i==n]);
            fflush(stdout);
        }
    }
    return 0;
}