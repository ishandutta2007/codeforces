#include <bits/stdc++.h>

using namespace std;
#define int long long
int to(vector <int> v)
{
    if(v.empty())
    {
        return 0;
    }
    int n=v.size();
    int m=v[(n-1)/2];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=abs(v[i]-m);
    }
    return ans;
}
int slv(vector <int> a,int x)
{
    if(x==1)
    {
        return 1e18;
    }
    int curr=0;
    int z=0;
    vector <int> v;
    int n=a.size();
    int s=0;
    while(curr<n)
    {
        if(v.size()!=x)
        {
            if(a[curr]==1)
            {
            v.push_back(curr);
            }
            ++curr;
        }
        else
        {
            s+=to(v);
            v.clear();
        }
    }
    s+=to(v);
    //cout<<s<<" "<<x<<endl;
    return s;
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
    for(int i=1;i*i<=s;++i)
    {
        if(s%i==0)
        {
            ans=min(ans,slv(a,i));
            ans=min(ans,slv(a,s/i));
        }
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