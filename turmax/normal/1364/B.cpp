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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector <int> v;
    v.push_back(a[0]);
    for(int i=1;i<(n-1);++i)
    {
        if((a[i]-a[i-1])*(a[i]-a[i+1])>0)
        {
            v.push_back(a[i]);
        }
    }
    v.push_back(a[n-1]);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    }
    return 0;
}