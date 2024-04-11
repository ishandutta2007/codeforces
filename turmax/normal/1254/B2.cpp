#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv(vector <int> a,int x)
{
    if(x==1)
    {
        return 1e18;
    }
    int curr=0;
    int ans=0;
    int n=a.size();
    for(int i=0;i<n;++i)
    {
        ans+=min(curr,x-curr);
        curr+=a[i];
        curr%=x;
    }
    return ans;
}
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1)
    {
        return v;
    }
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    int s=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    int ans=1e18;
    vector <int> v=rasl(s);
    for(int i=0;i<v.size();++i)
    {
        ans=min(ans,slv(a,v[i]));
    }
    if(ans==1e18)
    {
        cout<<(-1);
    }
    else
    {
        cout<<ans;
    }
    return 0;
}