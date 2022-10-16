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

const int maxn = 64;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

const int MAXM = 256;
using Vec = array<int,MAXM+1>;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        vector<Vec> A;
        static int id[maxn][maxn],x[MAXM],y[MAXM],w[MAXM];
        int n,m; scanf("%d%d",&n,&m);
        memset(id,-1,sizeof id);
        rep(i,0,m-1)
        {
            scanf("%d%d%d",&x[i],&y[i],&w[i]); x[i]--; y[i]--; if(w[i]>0) w[i]--;
            id[x[i]][y[i]] = id[y[i]][x[i]] = i;
        }
        rep(i,0,n-1) rep(j,i+1,n-1) rep(k,j+1,n-1)
        {
            if(id[i][j]!=-1 && id[j][k]!=-1 && id[k][i]!=-1)
            {
                static vi vec; vec.clear();
                vec.pb(id[i][j]);
                vec.pb(id[j][k]);
                vec.pb(id[k][i]);
                Vec V{};
                for(auto I: vec)
                {
                    if(w[I]==-1) V[I] = 1;
                    else V[m] = (V[m]-w[I]+3)%3;
                }
                A.pb(V);
                rep(j,0,m) debug(i,j,V[j]);
            }
        }
        int rank = 0, N = sz(A);
        rep(i,0,m-1)
        {
            int tmp = -1;
            rep(j,rank,N-1) if(A[j][i]) {tmp = j; break;}
            if(tmp==-1) continue;
            else swap(A[tmp],A[rank]);
            if(A[rank][i]==2) rep(k,i,m) A[rank][k] = (3-A[rank][k])%3;
            rep(j,0,N-1) if(j!=rank && A[j][i])
            {
                int fac = A[j][i];
                rep(k,i,m) A[j][k] = (A[j][k] - A[rank][k]*fac%3 + 3)%3;
            }
            rank++;
        }
        int ok = 1;
        rep(i,rank,N-1) if(A[i][m]) ok = 0;
        if(ok==0) puts("-1");
        else
        {
            rep(i,0,rank-1)
            {
                rep(k,0,m-1) if(A[i][k])
                {
                    w[k] = A[i][m];
                    break;
                }
            }
            rep(i,0,m-1) if(w[i]==-1) w[i] = 0;
            rep(i,0,m-1) printf("%d%c",w[i]+1," \n"[i==m-1]);
        }
    }
    return 0;
}