#include <bits/stdc++.h>

using namespace std;
#define int long long
bool check(vector<pair<int,int> > a,int k,int s)
{
    int sum=0;
    int n=a.size();
    int u=0;
    for(int i=0;i<n;++i)
    {
        if(a[i].first>=k)
        {
            ++u;
        }
        sum+=a[i].first;
    }
    int t=(n+1)/2-u;
    vector <int> b;
    for(int i=0;i<n;++i)
    {
        if(a[i].first<k && a[i].second>=k)
        {
            b.push_back(k-a[i].first);
        }
    }
    if(b.size()<t)
    {
        return false;
    }
    sort(b.begin(),b.end());
    for(int i=0;i<t;++i)
    {
        sum+=b[i];
    }
    return sum<=s;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    int n,s;
    vector <pair<int,int> > a;
    int l,r;
    int low,up;
    int k;
    for(int i=0;i<q;++i)
    {
        cin>>n>>s;
        a.resize(n);
        for(int j=0;j<n;++j)
        {
            cin>>l>>r;
            a[j]={l,r};
        }
        sort(a.begin(),a.end());
        low=0;
        up=1e18;
        while(true)
        {
            if((up-low)==1)
            {
                cout<<low<<endl;
                break;
            }
            k=(up+low)/2;
            if(check(a,k,s))
            {
                low=k;
            }
            else
            {
                up=k;
            }
        }
    }
    return 0;
}