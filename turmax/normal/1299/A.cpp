#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    vector <vector <int> > b(30);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        for(int j=0;j<30;++j)
        {
            if((a[i]>>j)&1)
            {
                b[j].push_back(i);
            }
        }
    }
    int t;
    for(int i=29;i>=0;i--)
    {
        if(b[i].size()==1)
        {
            t=b[i][0];
            cout<<a[t]<<" ";
            for(int i=0;i<t;++i)
            {
                cout<<a[i]<<" ";
            }
            for(int i=(t+1);i<n;++i)
            {
                cout<<a[i]<<" ";
            }
            exit(0);
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}