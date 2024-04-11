#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,MOD=1e9+7;

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

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1,greater<>());
        int val=a[k],all=0,need=0;
        for(int i=1;i<=n;i++)
            if(a[i]==val)
                all++,
                need+=i<=k;
        int ans=1;
        for(int i=all-need+1;i<=all;i++)
            ans=ans*i%MOD;
        for(int i=1;i<=need;i++)
            ans=ans*ppow(i,MOD-2)%MOD;
        cout<<ans<<"\n";
    }
}