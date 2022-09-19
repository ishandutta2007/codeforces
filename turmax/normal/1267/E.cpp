#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[m][n];
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    vector <int> v;
    pair<int,vector <int> > u;
    u.first=1e18;
    int sum;
    int sum1;
    vector <pair<int,int> > d(m);
    int t;
    int c;
    for(int i=0;i<(n-1);++i)
    {
        v.clear();
        sum=0;
        sum1=0;
        for(int j=0;j<m;++j)
        {
            sum+=a[j][i];
            sum1+=a[j][n-1];
        }
        if(sum>=sum1)
        {
            u=min(u,{0,v});
            continue;
        }
        t=sum1-sum;
        //cout<<t<<endl;
        for(int j=0;j<m;++j)
        {
            d[j]={a[j][n-1]-a[j][i],j};
        }
        sort(d.begin(),d.end());
        reverse(d.begin(),d.end());
        c=0;
        while(t>0)
        {
            v.push_back(d[c].second);
            t-=d[c].first;
            ++c;
        }
        //cout<<v.size()<<" tgrfd "<<endl;
        u=min(u,{v.size(),v});
    }
    cout<<u.first<<endl;
    v=u.second;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    return 0;
}