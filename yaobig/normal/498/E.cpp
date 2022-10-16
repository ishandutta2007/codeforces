#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int dp[1<<7];
int w[10];

struct mat
{
    int n;
    int a[1<<7][1<<7];
    mat(){}
    mat(int N):n(N){rep(i,0,N-1) rep(j,0,N-1) a[i][j]=0;}
    int* operator [](const int &i) const {return (int*)a[i];}
    mat operator *(const mat& B) const 
    {
        mat C(n);
        rep(i,0,n-1) rep(k,0,n-1) rep(j,0,n-1) C[i][j]=(C[i][j]+1ll*a[i][k]*B[k][j])%mod;
        return C;
    }
};

mat qp(mat A,ll k)
{
    mat res(A.n);
    rep(i,0,res.n-1) res[i][i]=1;
    while(k)
    {
        if(k&1) res=res*A;
        A=A*A;
        k>>=1;
    }
    return res;
}

void solve(int n)
{
    int H=1<<(n-1);
    rep(i,0,H-1) swap(dp[i+(1<<(n-1))],dp[i]);
    mat A(1<<n);
    vi MSK;
    rep(i,0,n-1)
    {
        int msk=(1<<i) | (1<<(n+i));
        if(i!=0) msk |= 1<<(n*2+i-1);
        if(i!=n-1) msk |= 1<<(n*2+i);
        MSK.pb(msk);
    }
    rep(s,0,(1<<(n*3-1))-1)
    {
        bool ok=1;
        for(auto msk: MSK) if((s&msk)==msk) {ok=0; break;}
        if(ok) A[s&((1<<n)-1)][(s>>n)&((1<<n)-1)]++;
    }
    A=qp(A,w[n]);
    vi b(1<<n,0);
    rep(j,0,(1<<n)-1) rep(i,0,(1<<n)-1) b[j]=(b[j]+1ll*A[i][j]*dp[i])%mod;
    rep(i,0,(1<<n)-1) dp[i]=b[i];
    
}

int main()
{
    dp[0]=1;
    rep(i,1,7) scanf("%d",&w[i]),solve(i);
    printf("%d\n",dp[(1<<7)-1]);
    return 0;
}