#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    map<vector<int>,int> a;
    int b[n][k];
    for(int i=0;i<n;++i)
    {
        vector<int> v;
        for(int j=0;j<k;++j)
        {
            int x;cin>>x;b[i][j]=x;v.push_back(x);
        }
        a[v]=i;
    }
    int h[n]={0};
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            vector<int> u;
            for(int l=0;l<k;++l)
            {
                u.push_back((6-b[i][l]-b[j][l])%3);
            }
            if(!a.count(u)) continue;
            int id=a[u];
            if(id!=i && id!=j) h[id]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i) ans+=(h[i]*(h[i]-1)/2);
    cout<<ans;
    return 0;
}