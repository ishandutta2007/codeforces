#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int res=INT_MAX;
        for(int j=0;j<m;j++)
        {
            int c;
            cin>>c;
            res=min(res,c);
        }
        ans=max(ans,res);
    }
    cout<<ans;
}