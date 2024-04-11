#include<bits/stdc++.h>

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

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum=0;
    for(int i=0;i<=n-3;i+=2)
        sum+=a[i];
    int ans=1e18;
    for(int l=0,r=n-3;l<n;sum-=a[l],l+=2,r=(r+2)%n,sum+=a[r])
        ans=min(ans,sum);
    sum=0;
    for(int i=1;i<=n-2;i+=2)
        sum+=a[i];
    for(int l=1,r=n-2;l<n;sum-=a[l],l+=2,r=(r+2)%n,sum+=a[r])
        ans=min(ans,sum);
    cout<<accumulate(a,a+n,0ll)-ans;
}