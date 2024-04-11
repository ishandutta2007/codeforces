#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=998244353 ;

int x[N],y[N],s[N],dp[N],pref[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i]>>s[i];
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(x+1,x+i+1,y[i])-x;
        dp[i]=(pref[i-1]-pref[pos-1]+x[i]-y[i]+10*MOD)%MOD;
        pref[i]=(pref[i-1]+dp[i])%MOD;
    }
    int ans=(x[n]+1)%MOD;
    for(int i=1;i<=n;i++)
        if(s[i])
            ans=(ans+dp[i])%MOD;
    cout<<ans;
}