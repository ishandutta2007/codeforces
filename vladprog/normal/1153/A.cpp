#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,t;
    cin>>n>>t;
    pair<int,int> ans={1e9,-1};
    for(int i=1;i<=n;i++)
    {
        int s,d;
        cin>>s>>d;
        if(s<t)
            s+=(t-s+d-1)/d*d;
        ans=min(ans,{s,i});
    }
    cout<<ans.second;
}