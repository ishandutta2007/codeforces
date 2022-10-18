#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100,MOD=998244353;

int a[N];

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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++)
        cin>>a[i];
    sort(a+1,a+2*n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans-=a[i];
    for(int i=1;i<=n;i++)
        ans+=a[n+i];
    ans%=MOD;
    int x=1;
    for(int i=1;i<=n;i++)
        x=x*i%MOD;
    int y=1;
    for(int i=1;i<=n;i++)
        y=y*(n+i)%MOD;
    cout<<ans*ppow(x,MOD-2)%MOD*y%MOD;
}