#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int M=1e5+100;

int cnt[M];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            cnt[x%m]++;
        }
        int ans=0;
        if(cnt[0])
            ans++;
        if(m%2==0&&cnt[m/2])
            ans++;
        for(int i=1,j=m-1;i<j;i++,j--)
            if(cnt[i]||cnt[j])
                ans+=max(1ll,abs(cnt[i]-cnt[j]));
        cout<<ans<<"\n";
    }
}