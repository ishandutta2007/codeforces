#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>(n-k))
        {
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    cout<<(n*(n+1)/2-((n-k)*(n-k+1))/2)<<" ";
    int ans=1;
    for(int i=0;i<v.size()-1;++i)
    {
        ans*=(v[i+1]-v[i]);
        ans%=p;
    }
    cout<<ans;
    return 0;
}