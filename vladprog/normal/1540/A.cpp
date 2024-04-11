#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int d[N];

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
            cin>>d[i];
        sort(d+1,d+n+1);
        int ans=d[n];
        for(int i=1;i<=n;i++)
            ans+=d[i]*(n-2*i+1);
        cout<<ans<<"\n";
    }
}