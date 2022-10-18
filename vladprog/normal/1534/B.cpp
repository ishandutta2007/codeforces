#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=4e5+100;

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        a[0]=a[n+1]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int cur=max(0ll,min(a[i]-a[i-1],a[i]-a[i+1]));
            ans+=cur;
            a[i]-=cur;
        }
        for(int i=0;i<=n;i++)
            ans+=abs(a[i]-a[i+1]);
        cout<<ans<<"\n";
    }
}