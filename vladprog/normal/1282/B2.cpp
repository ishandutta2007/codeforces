#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

int a[N],pref[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k;
        cin>>n>>p>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            pref[i]=a[i]+pref[i-1];
        int ans=0;
        for(int i=0;i<=k-1;i++)
        {
            int s=pref[i];
            if(s>p)
                continue;
            int j=i;
            while(j+k<=n&&s+a[j+k]<=p)
                s+=a[j+k],
                j+=k;
            ans=max(ans,j);
        }
        cout<<ans<<"\n";
    }
}