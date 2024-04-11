#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    unordered_map <int,int> d;
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(d.count(a[i])==0)
        {
            d[a[i]]=1;
            v.push_back(a[i]);
        }
        else
        {
            d[a[i]]++;
        }
    }
    int ma=0;
    for(int i=0;i<n;++i)
    {
        ma=max(ma,d[a[i]]);
    }
    int d1,d2;
    int l=(-1);
    int ma1=(-1);
    int val;
    int sum;
    int o=v.size();
    vector <int> z(v.size());
    for(int i=0;i<z.size();++i)
    {
        z[i]=d[v[i]];
    }
    for(int d1=1;d1*d1<=n;++d1)
    {
        val=d1*(n/d1);
        sum=0;
        for(int i=0;i<o;++i)
        {
            sum+=min(z[i],d1);
        }
        if(sum<(d1*d1))
        {
            continue;
        }
        val=min(val,d1*(sum/d1));
        if(val>ma1)
        {
            ma1=val;
            l=d1;
        }
    }
    d1=l;
    d2=(ma1/d1);
    int y=0;
    int ans[d1][d2];
    bool used1[d1][d2];
    for(int i=0;i<d1;++i)
    {
        for(int j=0;j<d2;++j)
        {
            used1[i][j]=false;
        }
    }
    int u1,v1;
    vector <pair<int,int> > to1;
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<min(d1,z[i]);++j)
        {
            to1.push_back({min(d1,z[i]),v[i]});
        }
    }
    vector <int> to;
    sort(to1.begin(),to1.end());
    reverse(to1.begin(),to1.end());
    for(int i=0;i<to1.size();++i)
    {
        to.push_back(to1[i].second);
    }
    int r=0;
    for(int x=0;x<d1;++x)
    {
        u1=x;
        v1=0;
        while(!used1[u1][v1])
        {
            ans[u1][v1]=to[r];
            used1[u1][v1]=true;
            ++r;
            ++u1;
            ++v1;
            u1%=d1;
            v1%=d2;
        }
    }
    cout<<d1*d2<<endl;
    cout<<d1<<" "<<d2<<endl;
    for(int i=0;i<d1;++i)
    {
        for(int j=0;j<d2;++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}