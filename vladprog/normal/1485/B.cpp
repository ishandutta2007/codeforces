#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N],cnt[N],sum[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q,k;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[0]=0,a[n+1]=k+1;
    for(int i=1;i<=n;i++)
        cnt[i]=a[i+1]-a[i-1]-2,
        sum[i]=sum[i-1]+cnt[i];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(l==r)
        {
            cout<<k-1<<"\n";
            continue;
        }
        int ans=sum[r-1]-sum[l];
        ans+=a[l+1]-0-2;
        ans+=k+1-a[r-1]-2;
        cout<<ans<<"\n";
    }
}