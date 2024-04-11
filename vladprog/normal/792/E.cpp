#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=510;

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
    int sq=sqrt(a[1])+1;
    unordered_set<int> can;
    for(int i=1;i<=sq;i++)
        can.insert(i),
        can.insert(a[1]/i),
        can.insert(a[1]/i-1);
    can.erase(0);
    int ans=1e18;
    for(int x:can)
    {
        bool ok=true;
        int res=0;
        for(int i=1;i<=n;i++)
            if(a[i]%x>a[i]/x)
            {
                ok=false;
                break;
            }
            else
                res+=(a[i]+x)/(x+1);
        if(ok)
            ans=min(ans,res);
    }
    cout<<ans;
}