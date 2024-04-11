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
        int n,k;
        cin>>n>>k;
        pair <int,int> a[k];
        int ans=0;
        int u1[k];int u2[k];
        for(int i=0;i<k;++i) {cin>>a[i].first>>a[i].second;a[i].first--;a[i].second--;if(a[i].first>a[i].second) swap(a[i].first,a[i].second);u1[i]=(a[i].second-a[i].first-1);u2[i]=(a[i].first+2*n-a[i].second-1);}
        for(int i=0;i<k;++i) for(int j=0;j<k;++j)
        {
            if(max(a[i].first,a[i].second)<min(a[j].first,a[j].second) || min(a[i].first,a[i].second)>max(a[j].first,a[j].second))
            {
                u2[i]-=2;
            }
            else if(a[i].second>a[j].second && a[i].first<a[j].first)
            {
                u1[i]-=2;
            }
            else if(a[j].second>a[i].second && a[j].first<a[i].first)
            {
                u2[i]-=2;
            }
            else if(i!=j)
            {
                ++ans;
                u1[i]--;u2[i]--;
            }
        }
        ans+=(n-k)*(n-k-1);
        for(int i=0;i<k;++i) {ans+=2*min(u1[i],u2[i]);}
        cout<<ans/2<<'\n';
    }
    return 0;
}