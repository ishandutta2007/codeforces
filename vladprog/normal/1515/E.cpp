#pragma GCC optimize("03")
//#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

int read()
{
    int x;
    cin>>x;
    return x;
}

void write(int x)
{
    cout<<x;
}

typedef pair<int,int> pii;
#define x first
#define y second

const int NMAX=410;

int dp[NMAX][NMAX];
int MOD;
int fact[NMAX],rfact[NMAX];

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int C[NMAX][NMAX];

#define FOR(i,from,to) for(int i=(from),i##_to=(to);i<=i##_to;i++)

signed main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int N=read();
    MOD=read();
    fact[0]=1;
    for(int i=1;i<=N;i++)
        fact[i]=fact[i-1]*i%MOD;
    rfact[N]=ppow(fact[N],MOD-2);
    for(int i=N-1;i>=0;i--)
        rfact[i]=rfact[i+1]*(i+1)%MOD;
    for(int n=0;n<=N;n++)
        for(int k=0;k<=n;k++)
            C[n][k]=fact[n]*rfact[k]%MOD*rfact[n-k]%MOD;
    dp[1][1]=1;
    FOR(n,2,N) FOR(k,n/2,n)
    {
        FOR(l,0,k-1)
        {
            __int128 ans11=0;
            if(max(l+1,n-2*(k-l-1)-1)<=1&&1<=min(n-(k-l-1),2*l+2))
            {
                //p=1;
//                cout<<n<<" "<<k<<" "<<l<<" "<<1<<"\n";
                ans11=(dp[n-2][k-1-l]+
                       dp[n-1][k-1-l]);
            }
            if(max(l+1,n-2*(k-l-1)-1)<=n&&n<=min(n-(k-l-1),2*l+2))
            {
                //p=n;
//                cout<<n<<" "<<k<<" "<<l<<" "<<n<<"\n";
                ans11+=(dp[n-2][l]+
                        dp[n-1][l]);
            }
            FOR(p,max({l+1,n-2*(k-l-1)-1,2ll}),min({n-(k-l-1),2*l+2,n-1}))
            {
//                cout<<n<<" "<<k<<" "<<l<<" "<<p<<"\n";
                ans11+=((dp[p-2][l]+dp[p-1][l])*
                        (dp[n-p-1][k-1-l]+dp[n-p][k-1-l])-
                        dp[p-1][l]*dp[n-p][k-1-l]);
            }
            int mul=C[k-1][l];
//            cout<<n<<" "<<k<<" "<<l<<" -> "<<int(ans11)<<" * "<<mul<<"\n";
            dp[n][k]+=(ans11*mul%MOD);
        }
        dp[n][k]%=MOD;
//        cout<<"!!!!! "<<n<<" "<<k<<" -> "<<dp[n][k]<<"\n";
    }
    int ans=0;
    FOR(k,N/2,N)
        ans+=dp[N][k];
    write((ans%MOD+MOD)%MOD);
}