#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e5+100;

int a[2*N];

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
        int s=0;
        for(int i=1;i<=2*n;i++)
            cin>>a[i],
            a[i]=(a[i]==1?1:-1),
            s+=a[i];
        map<int,int> mx;
        int cur=0;
        mx[cur]=0;
        for(int i=1;i<=n;i++)
            cur+=a[i],
            mx[cur]=i;
        int ans=1e9;
        if(mx.count(cur-s))
            ans=min(ans,n-mx[cur-s]);
        for(int i=n+1;i<=2*n;i++)
        {
            cur+=a[i];
            if(mx.count(cur-s))
                ans=min(ans,i-mx[cur-s]);
        }
        cout<<ans<<"\n";
    }
}