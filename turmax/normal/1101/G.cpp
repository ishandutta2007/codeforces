#include <bits/stdc++.h>

using namespace std;
#define int long long
int basis(vector <int> v)
{
    for(int i=0;i<min(40LL,(int) v.size());++i)
    {
        sort(v.begin()+i,v.end());
        reverse(v.begin()+i,v.end());
        if(v[i]==0)
        {
            return i;
        }
        for(int j=(i+1);j<v.size();++j)
        {
            v[j]=min(v[j],v[j]^v[i]);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int pr[n+1];pr[0]=0;
    for(int i=0;i<n;++i) pr[i+1]=pr[i]^a[i];
    vector <int> v;
    for(int i=0;i<=n;++i) v.push_back(pr[i]);
    if(pr[n]==0) {cout<<(-1);return 0;}
    int ans=basis(v);
    if(ans!=0)
    cout<<ans;
    else
    cout<<(-1);
    return 0;
}