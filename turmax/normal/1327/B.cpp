#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    vector <int> g[n];
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        g[i].resize(x);
        for(int j=0;j<x;++j)
        {
            cin>>g[i][j];
            g[i][j]--;
        }
    }
    int is[n];
    bool used[n];
    for(int i=0;i<n;++i)
    {
        is[i]=(-1);
        used[i]=false;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<g[i].size();++j)
        {
            if(!used[g[i][j]])
            {
                is[i]=g[i][j];
                used[g[i][j]]=true;
                break;
            }
        }
    }
    bool h=true;
    int l;
    for(int i=0;i<n;++i)
    {
        if(is[i]==(-1))
        {
            h=false;
            l=i;
            break;
        }
    }
    if(h)
    {
        cout<<"OPTIMAL"<<endl;
    }
    else
    {
        cout<<"IMPROVE"<<endl;
        for(int i=0;i<n;++i)
        {
            if(!used[i])
            {
                cout<<(l+1)<<" "<<(i+1)<<endl;
                break;
            }
        }
    }
    }
    return 0;
}