#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3500;

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
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        k=min(k,m-1);
        int x=n-k;
        int y=n-m+1;
        int ans=0;
        for(int i=1;i+x-1<=n;i++)
        {
            int res=2e9;
            for(int j=i;j+y-1<=i+x-1;j++)
                res=min(res,max(a[j],a[j+y-1]));
            ans=max(ans,res);
        }
        cout<<ans<<"\n";
    }
}