#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int a[17];

int solve(int l,int r)
{
    int ans=(l==r?1:max(solve(l,(l+r)/2),solve((l+r)/2+1,r)));
    bool ok=true;
    for(int i=l+1;i<=r;i++)
        if(a[i]<a[i-1])
            ok=false;
    return max(ans,(ok?r-l+1:0));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<solve(1,n);
}