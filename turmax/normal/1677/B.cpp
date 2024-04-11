#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;string s;cin>>s;
        bool res[m]={0};int ans[n*m]={0};int o[n*m];for(auto &h:o) h=0;for(int i=0;i<n*m;++i) {if(i!=0) {ans[i]=ans[i-1];} int x=s[i]-'0';if(x) {if(!res[i%m]) {res[i%m]=true;ans[i]++;}}}
        int cur=0;int sum=s[0]-'0';
        while(cur<n*m)
        {
            if(sum) {o[cur]++;}
            if(cur==(n*m-1)) break;
            sum+=(s[cur+1]-'0');if(cur-m+1>=0) {sum-=(s[cur-m+1]-'0');}++cur;
        }
        //for(int i=0;i<n*m;++i) cout<<o[i]<<endl;
        for(int i=m;i<n*m;++i) {o[i]+=o[i-m];}
        for(int i=0;i<n*m;++i) {cout<<ans[i]+o[i]<<' ';} cout<<endl;
    }
    return 0;
}