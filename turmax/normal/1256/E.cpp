#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    map <int,vector <int> > b;
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(b.count(a[i])==0)
        {
            v.clear();
            v.push_back(i);
            b[a[i]]=v;
        }
        else
        {
            b[a[i]].push_back(i);
        }
    }
    sort(a,a+n);
    int sum[n+1];
    int pr[n+1];
    sum[0]=0;
    sum[1]=1e18;
    sum[2]=1e18;
    pr[0]=(-1);
    pr[1]=(-1);
    pr[2]=(-1);
    for(int i=3;i<=n;++i)
    {
        if(i==3)
        {
            sum[i]=(a[i-1]-a[i-3]+sum[i-3]);
            pr[i]=(i-3);
        }
        else if(i==4)
        {
            sum[i]=min(a[i-1]-a[i-3]+sum[i-3],a[i-1]-a[i-4]+sum[i-4]);
            if(sum[i]==a[i-1]-a[i-3]+sum[i-3])
            {
                pr[i]=(i-3);
            }
            if(sum[i]==a[i-1]-a[i-4]+sum[i-4])
            {
                pr[i]=(i-4);
            }
        }
        else
        {
            sum[i]=min(min(a[i-1]-a[i-3]+sum[i-3],a[i-1]-a[i-4]+sum[i-4]),a[i-1]-a[i-5]+sum[i-5]);
            if(sum[i]==a[i-1]-a[i-3]+sum[i-3])
            {
                pr[i]=(i-3);
            }
            if(sum[i]==a[i-1]-a[i-4]+sum[i-4])
            {
                pr[i]=(i-4);
            }
            if(sum[i]==a[i-1]-a[i-5]+sum[i-5])
            {
                pr[i]=(i-5);
            }
        }
    }
    int x=n;
    int y;
    int ans[n];
    int curr=1;
    int z;
    while(x!=0)
    {
        y=pr[x];
        for(int i=y;i<x;++i)
        {
            z=b[a[i]][b[a[i]].size()-1];
            b[a[i]].erase(b[a[i]].begin()+b[a[i]].size()-1);
            ans[z]=curr;
        }
        ++curr;
        x=y;
    }
    cout<<sum[n]<<" "<<curr-1<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}