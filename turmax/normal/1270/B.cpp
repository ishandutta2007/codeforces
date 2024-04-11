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
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    bool h=true;
    for(int i=0;i<(n-1);++i)
    {
        if(abs(a[i+1]-a[i])>=2)
        {
            cout<<"YES"<<endl;
            cout<<(i+1)<<" "<<(i+2)<<endl;
            h=false;
            break;
        }
    }
    if(h)
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}