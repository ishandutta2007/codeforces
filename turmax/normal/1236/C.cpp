#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a[n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i%2==0)
            {
                a[j].push_back(i*n+j);
            }
            else
            {
                a[n-1-j].push_back(i*n+j);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<a[i][j]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}