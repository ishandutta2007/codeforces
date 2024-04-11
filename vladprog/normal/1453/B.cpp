#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

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
        int start=0;
        for(int i=1;i<=n-1;i++)
            start+=abs(a[i]-a[i+1]);
        int ans=min(start-abs(a[1]-a[2]),
                    start-abs(a[n]-a[n-1]));
        for(int i=2;i<=n-1;i++)
            ans=min(ans,
                    start-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]));
        cout<<ans<<"\n";
    }
}