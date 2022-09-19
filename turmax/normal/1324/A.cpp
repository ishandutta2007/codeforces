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
        set <int> a;
        int x;
        for(int i=0;i<n;++i)
        {
            cin>>x;
            x%=2;
            a.insert(x);
        }
        if(a.size()==1)
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