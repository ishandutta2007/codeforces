#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    int k;
    int o=0;
    int s=0;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        if(k%2==0)
        {
            s=1;
        }
        else
        {
            o=1;
        }
        a[i]=k;
    }
    if(s==1 && o==1)
    {
        sort(a.begin(),a.end());
        for(int i=0;i<n;++i)
        {
            cout<<a[i]<<" ";
        }
        return 0;
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            cout<<a[i]<<" ";
        }
        return 0;
    }
    return 0;
}