#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    int ans=a[0];
    int s=accumulate(a,a+n,0ll);
    for(int i=1;i<n;i++)
    {
        if(!a[i])
            break;
        if(a[i-1]==1)
            ans++;
        a[i]=min(a[i],max(1ll,a[i-1]-1));
    }
    cout<<s-ans;
}