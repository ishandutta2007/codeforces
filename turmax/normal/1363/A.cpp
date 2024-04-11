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
    int n,x;
    cin>>n>>x;
    int a[n];
    set <int> d;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
        d.insert(a[i]%2);
    }
    if(x==n)
    {
        if(sum%2)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else
        {
            cout<<"No"<<endl;
            continue;
        }
    }
    if(d.size()==2)
    {
        cout<<"Yes"<<endl;
        continue;
    }
    if(d.size()==1)
    {
        if(x%2==0 || a[0]%2==0)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    }
    return 0;
}