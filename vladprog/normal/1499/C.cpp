#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,INF=1e18;

int c[N];

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
            cin>>c[i];
        int cnt[2]={};
        int sum[2]={};
        int mn[2]={INF,INF};
        int ans=INF;
        for(int i=1;i<=n;i++)
        {
            cnt[i%2]++;
            sum[i%2]+=c[i];
            mn[i%2]=min(mn[i%2],c[i]);
            if(i==1)
                continue;
            ans=min(ans,sum[0]+mn[0]*(n-cnt[0])+
                        sum[1]+mn[1]*(n-cnt[1]));
        }
        cout<<ans<<"\n";
    }
}