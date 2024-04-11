#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
using ll = long long;
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 500010;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

ll op_msk[15],op_new_msk[15],nxt[15][45];
int ub[15];
int n,k;

void dfs(int now,int cnt,ll msk)
{
    if(now>k)
    {
        if(msk!=(1ll<<cnt)-1) {puts("REJECTED"); exit(0);}
        return;
    }
    rep(i,0,ub[now])
    {
        int ncnt=cnt+i;
        int c=__builtin_popcountll(msk & op_msk[now])+i;
        ll nmsk=((msk | op_msk[now]) ^ op_msk[now]) | nxt[now][c];
        dfs(now+1,ncnt,nmsk);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    rep(i,1,k)
    {
        int q; scanf("%d",&q); rep(j,1,q)
        {
            int x; scanf("%d",&x); op_msk[i] |= 1ll<<(x-1);
            nxt[i][j]=op_msk[i];
        }
    }
    ll MSK=0;
    rep(i,1,k)
    {
        ll cup=MSK | op_msk[i];
        op_new_msk[i]=cup^MSK;
        ub[i]=__builtin_popcountll(op_new_msk[i]);
        MSK=cup;
    }
    if(n==1) {puts("ACCEPTED"); exit(0);}
    if(__builtin_popcountll(MSK)!=n) {puts("REJECTED"); exit(0);}

    dfs(1,0,0);
    puts("ACCEPTED");
    return 0;
}