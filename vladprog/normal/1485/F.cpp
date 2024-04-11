#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=1e9+7;

int b[N],pref[N],nxt[N],dp[N];

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
            cin>>b[i],pref[i]=pref[i-1]+b[i];
        map<int,int> last;
        for(int i=n;i>=0;i--)
            nxt[i]=(last.count(pref[i])?last[pref[i]]:n+1),
            last[pref[i]]=i;
        for(int i=0;i<=n;i++)
            dp[i]=0;
        dp[0]=1;
        dp[1]=-1;
        for(int i=0;i<=n;i++)
        {
            if(i)
                (dp[i]+=dp[i-1])%=MOD;
//            cout<<"dp["<<i<<"]="<<dp[i]<<" : "<<i+1<<" .. "<<nxt[i]-1<<"\n";
            (dp[i+1]+=dp[i])%=MOD;
            (dp[nxt[i]+1]-=dp[i])%=MOD;
        }
        cout<<(dp[n]+MOD)%MOD<<"\n";
    }
}