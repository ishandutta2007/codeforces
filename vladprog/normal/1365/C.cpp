#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],b[N],pa[N],pb[N],cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        pa[a[i]]=i;
    for(int i=1;i<=n;i++)
        cin>>b[i],
        pb[b[i]]=i;
    for(int i=1;i<=n;i++)
        cnt[(pa[i]-pb[i]+n)%n]++;
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,cnt[i]);
    cout<<ans;
}