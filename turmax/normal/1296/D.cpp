#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,a,b,k;
int go(int x)
{
    x%=(a+b);
    if(x==0)
    {
        x=(a+b);
    }
    return (x-1)/a;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>a>>b>>k;
    vector <int> v(n);
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        v[i]=go(x);
        //cout<<v[i]<<endl;
    }
    sort(v.begin(),v.end());
    int ans=0;
    int s=0;
    for(int i=0;i<n;++i)
    {
        if((s+v[i])>k)
        {
            break;
        }
        else
        {
            s+=v[i];
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}