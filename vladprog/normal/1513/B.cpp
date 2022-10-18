#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=1e9+7;

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
        int val=a[1];
        for(int i=1;i<=n;i++)
            val&=a[i];
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=a[i]==val;
        int ans=cnt*(cnt-1)%MOD;
        for(int i=1;i<=n-2;i++)
            ans=ans*i%MOD;
        cout<<ans<<"\n";
    }
}