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
        int cnt1=0,cnt2=0,cnt0=0;bool h=false;map <int,int> u;
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) {cin>>a[i];u[a[i]]=1;if(a[i]==1) ++cnt1; else if(a[i]>=2) {++cnt2;} else ++cnt0;}
        for(auto [key,val]:u) if(u.count(key+1)) h=true;
        cout<<((h && cnt1)  ? "NO" : "YES")<<'\n';
    }
    return 0;
}