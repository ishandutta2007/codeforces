#include <bits/stdc++.h>

using namespace std;
#define int long long
int go2(vector <int> v)
{
    int sum1=0;// ones
    int sum2=0;// zeros
    for(int i=0;i<v.size();++i)
    {
        if(!v[i])
        {
            ++sum2;
        }
    }
    int ans=1e18;
    for(int i=0;i<v.size();++i)
    {
        ans=min(ans,sum1+sum2);
        if(v[i])
        {
            ++sum1;
        }
        else
        {
            --sum2;
        }
    }
    ans=min(ans,sum1+sum2);
    return ans;
}
int go1(vector <int> v)
{
    reverse(v.begin(),v.end());
    return go2(v);
}
int go(vector <int> v)
{
    if(v.size()==1)
    {
        return 0;
    }
    vector <int> h1,h2;
    pair <int,int> u1=make_pair(0,0);pair <int,int> u2=make_pair(0,0);
    int n=v.size();
    for(int i=0;i<(n/2);++i)
    {
        h1.push_back(v[i]);
        if(!v[i])
        {
            u1.first++;
        }
        else
        {
            u1.second++;
        }
    }
    for(int i=(n/2);i<n;++i)
    {
        h2.push_back(v[i]);
        if(!v[i])
        {
            u2.first++;
        }
        else
        {
            u2.second++;
        }
    }
    int ans=go2(h1)+go1(h2);
    ans=min(ans,go(h1)+u2.second);ans=min(ans,go(h2)+u1.second);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        pair <int,int> a[k];
        vector <int> v[k];
        for(int i=0;i<k;++i)
        {
            a[i].first=0;a[i].second=0;
        }
        for(int i=0;i<n;++i)
        {
            v[(i%k)].push_back(s[i]-'0');
            if(s[i]=='0')
            {
                a[(i%k)].first++;
            }
            else
            {
                a[(i%k)].second++;
            }
        }
        int sum=0;
        for(int i=0;i<k;++i)
        {
            sum+=a[i].second;
        }
        int ans=1e18;
        //cout<<sum<<" sum "<<endl;
        for(int i=0;i<k;++i)
        {
            ans=min(ans,sum-a[i].second+go(v[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}