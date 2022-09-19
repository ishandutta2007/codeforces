#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int cnt[maxn];
int ans[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<maxn;++i) {cnt[i]=0;ans[i]=0;}
        int n;
        cin>>n;
        for(int i=0;i<n;++i) {int x;cin>>x;cnt[x]++;ans[x]++;}
        for(int i=(maxn-1);i>=1;i--)
        {
            for(int j=(2*i);j<maxn;j+=i)
            {
                ans[i]=max(ans[i],cnt[i]+ans[j]);
            }
        }
        cout<<n-ans[1]<<endl;
    }
    return 0;
}