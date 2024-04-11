#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int n;
        cin>>n;
        int a[n];
        vector <int> b[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            a[i]--;
            b[a[i]].push_back(i);
        }
        bool h=false;
        for(int i=0;i<n;++i)
        {
            if(b[i].size()>=3)
            {
                h=true;
                break;
            }
            else if(b[i].size()==2 && (b[i][1]-b[i][0])!=1)
            {
                h=true;
                break;
            }
        }
        if(h)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}