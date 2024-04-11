#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;map <int,int> cnt;int a[n];for(int i=0;i<n;++i) {cin>>a[i];cnt[a[i]]++;}
        int res1=1;for(auto [key,val]:cnt) {res1+=min(val,2LL);}
        cout<<(res1/2)<<'\n';
    }
    return 0;
}