#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;int a[n];map <int,int> cnt;
        for(int i=0;i<n;++i) {cin>>a[i];cnt[a[i]]++;}
        sort(a,a+n);
        int ma=n;int sum=0;
        for(int i=0;i<=n;++i)
        {
            sum+=((bool) cnt[i]);
            if(sum+k<=i) {ma=min(ma,i);}
        }
        vector<int> v;
        for(auto [key,val]:cnt) {if(key>=ma) {v.push_back(val);}}
        sort(v.begin(),v.end());sum=0;int ans=0;
        for(int i=0;i<v.size();++i) {sum+=v[i];if(sum>k) {ans=v.size()-i;break;}}
        cout<<ans<<'\n';
    }
    return 0;
}