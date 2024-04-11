#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

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
        int k=(n+2)/2;
        int ans=(n-1)*(n-1);
        for(int i=2;i<=k-1;i++)
            ans+=(i-n)*(i-n);
        for(int i=k;i<=n-1;i++)
            ans+=(1-i)*(1-i);
        cout<<ans<<"\n";
        cout<<k<<" ";
        for(int i=1;i<=k-2;i++)
            cout<<i<<" ";
        for(int i=k+1;i<=n;i++)
            cout<<i<<" ";
        cout<<k-1<<"\n";
        cout<<n-1<<"\n";
        for(int i=k;i<=n-1;i++)
            cout<<i<<" "<<1<<"\n";
        for(int i=k-1;i>=2;i--)
            cout<<i<<" "<<n<<"\n";
        cout<<1<<" "<<n<<"\n";
    }
}