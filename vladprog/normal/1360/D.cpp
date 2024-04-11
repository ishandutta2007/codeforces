#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=55;

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
        int n,k;
        cin>>n>>k;
        int ans=n;
        for(int i=1;i*i<=n;i++)
            if(n%i==0)
            {
                {
                    int d=i;
                    if(d<=k)
                        ans=min(ans,n/d);
                }
                {
                    int d=n/i;
                    if(d<=k)
                        ans=min(ans,n/d);
                }
            }
        cout<<ans<<"\n";
    }
}