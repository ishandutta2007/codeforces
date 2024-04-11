#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=200;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[0]=0;
    a[n+1]=1001;
    int ans=1,t=0;
    for(int i=1;i<=n+1;i++)
        if(a[i]==a[i-1]+1)
            ans=max(ans,++t);
        else
            t=0;
    cout<<ans-1;
}