#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=105;

int a[N],b[N];
bitset<N*N> dp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        dp.reset();
        dp.set(0);
        int x=0,y=0;
        for(int i=1;i<=n;i++)
            dp|=dp<<abs(a[i]-b[i]),
            x+=min(a[i],b[i]),
            y+=abs(a[i]-b[i]);
        int z;
        for(int i=y/2;;i++)
            if(dp[i])
            {
                z=i;
                break;
            }
        int ans=(x+z)*(x+z)+(x+y-z)*(x+y-z);
        for(int i=1;i<=n;i++)
            ans+=(a[i]*a[i]+b[i]*b[i])*(n-2);
        cout<<ans<<"\n";
    }
}