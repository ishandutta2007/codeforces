#include <bits/stdc++.h>

using namespace std;
#define int long long
double merg(pair <int,int> u,pair <int,int> v)
{
    return -(u.second-v.second+0.0)/(u.first-v.first+0.0);
}
struct cht
{
    vector <pair<int,int> > v;
    vector <double> u;
    int get(int x)
    {
        if(!v.size())
        {
            return 1e18;
        }
        int o=lower_bound(u.begin(),u.end(),x)-u.begin();
        return v[o].first*x+v[o].second;
    }
    void push(int k,int b)
    {
        if(v.empty())
        {
            v.push_back({k,b});
            return;
        }
        pair <int,int> z={k,b};
        while(true)
        {
            pair <int,int> o=v.back();
            double x1=merg(z,o);
            if(!u.empty() && x1<u.back())
            {
                u.pop_back();
                v.pop_back();
            }
            else
            {
                v.push_back(z);
                u.push_back(x1);
                break;
            }
        }
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int dp[n+1];
    dp[0]=0;
    cht c;
    for(int i=0;i<n;++i)
    {
        dp[i+1]=a[i]*b[0];
        dp[i+1]=min(dp[i+1],c.get(a[i]));
        //cout<<dp[i+1]<<" dp "<<endl;
        c.push(b[i],dp[i+1]);
    }
    /*for(int i=0;i<=n;++i)
    {
        cout<<dp[i]<<endl;
    }
    cout<<endl;*/
    cout<<dp[n]<<endl;
    return 0;
}