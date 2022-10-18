#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int k[N],c[N];

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
        for(int i=1;i<=n;i++)
            cin>>k[i];
        for(int i=1;i<=m;i++)
            cin>>c[i];
        sort(k+1,k+n+1,greater<int>());
        int ans=0;
        for(int i=1;i<=n;i++)
            if(i<=k[i])
                ans+=c[i];
            else
                ans+=c[k[i]];
        cout<<ans<<"\n";
    }
}