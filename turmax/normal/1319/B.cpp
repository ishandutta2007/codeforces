#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    map <int,int> u;
    vector <int> keys;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        x=(i-a[i]);
        //cout<<x<<" x "<<endl;
        if(!u.count(x))
        {
            keys.push_back(x);
            u[x]=a[i];
        }
        else
        {
            u[x]+=a[i];
        }
    }
    int ans=(-1);
    for(int i=0;i<keys.size();++i)
    {
        ans=max(ans,u[keys[i]]);
    }
    cout<<ans;
    return 0;
}