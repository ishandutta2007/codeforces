#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n<=3)
    {
        cout<<0;
        exit(0);
    }
    int l=0;
    int ma=0;
    for(int k=1;k<=n;++k)
    {
        int curr=n-(n+k-1)/k-(k-1);
        if(curr>ma)
        {
            ma=curr;
            l=k;
        }
    }
    int k=l;
    bool is[n];
    bool used[n];
    vector <int> v;
    int curr=0;
    for(int i=0;i<n;++i)
    {
        used[i]=false;
        if(i==(n-1))
        {
            is[i]=false;
            break;
        }
        ++curr;
        if(curr!=k)
        {
            is[i]=true;
            v.push_back(i);
        }
        else
        {
            is[i]=false;
            curr=0;
        }
    }
    int ans=0;
    for(int i=0;i<10000;++i)
    {
        if(ans==ma)
        {
            cout<<0;
            exit(0);
        }
        vector <int> g;
        for(int i=0;i<v.size();++i)
        {
            if(!used[v[i]])
            {
                g.push_back(v[i]);
            }
        }
        int x=min((int) g.size(),k);
        cout<<x<<" ";
        for(int i=0;i<x;++i)
        {
            cout<<g[i]+1<<' ';
            used[g[i]]=true;
            ++ans;
        }
        int o;
        cin>>o;
        o--;
        for(int i=0;i<k;++i)
        {
            int y=(i+o)%n;
            if(used[y])
            {
                used[y]=false;
                ans--;
            }
        }
    }
    exit(0);
    return 0;
}