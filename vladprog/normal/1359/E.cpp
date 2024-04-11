#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100,MOD=998244353;

int f[N],r[N];

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

int c(int n,int k)
{
    if(k<0||k>n)
        return 0;
    return f[n]*r[k]%MOD*r[n-k]%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=f[i-1]*i%MOD;
    r[N-1]=ppow(f[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
        r[i]=r[i+1]*(i+1)%MOD;

    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+c(n/i-1,k-1))%MOD;
    cout<<ans;
}