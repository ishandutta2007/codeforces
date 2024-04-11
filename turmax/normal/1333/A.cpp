#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(i!=(n-1) || j!=(m-1))
            cout<<'B';
            else
            {
                cout<<'W';
            }
        }
        cout<<endl;
    }
    }
    return 0;
}