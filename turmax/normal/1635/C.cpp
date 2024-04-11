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
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int ans[n];
        int mi=n-1;int ma=n-1;int cur=1e18;
        pair <int,int> z;
        vector <vector<int> > v;
        bool flag=false;
        ans[n-1]=a[n-1];
        for(int i=(n-2);i>=0;--i)
        {
            if(a[i]<a[mi]) {mi=i;}
            if(i<(n-2) && a[i]>a[i+1]) {flag=true;}
            if(flag) {v.push_back({i+1,z.first+1,z.second+1});ans[i]=cur;}
            else {ans[i]=a[i];}
            if(!flag && (a[i]-a[ma])<=cur) {z={i,ma};cur=a[i]-a[ma];}
            if(a[i]>=a[ma]) {ma=i;}
        }
        if(is_sorted(ans,ans+n)) {reverse(v.begin(),v.end());cout<<v.size()<<endl;for(auto h:v) cout<<h[0]<<' '<<h[1]<<' '<<h[2]<<endl;continue;}
        else {cout<<(-1)<<endl;}
    }
    return 0;
}