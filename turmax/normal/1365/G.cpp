#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ans[n];
    int curr=0;
    for(int i=0;i<(1<<13);++i)
    {
        if(__builtin_popcount(i)==6)
        {
            if(curr<n)
            {
                ans[curr]=i;
                ++curr;
            }
        }
    }
    vector <int> b[13];
    for(int i=0;i<13;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(ans[j] & (1<<i))
            {
                b[i].push_back(j);
            }
        }
    }
    int o[13];
    for(int i=0;i<13;++i)
    {
        if(b[i].size()==0)
        {
            o[i]=0;
            continue;
        }
        cout<<"? "<<b[i].size()<<" ";
        for(int j=0;j<b[i].size();++j)
        {
            cout<<b[i][j]+1<<" ";
        }
        cout<<endl;
        int x;
        cin>>x;
        o[i]=x;
    }
    int res[n];
    for(int i=0;i<n;++i)
    {
        int u=ans[i];
        res[i]=0;
        for(int j=0;j<13;++j)
        {
            if(!(u & (1<<j)))
            {
                res[i]=(res[i] | o[j]);
            }
        }
    }
    cout<<"! "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<res[i]<<" ";
    }
    exit(0);
    return 0;
}