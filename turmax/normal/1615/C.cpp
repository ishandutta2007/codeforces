#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int a,int b)
{
    if(a==b) return 2*a;
    else return 1e9;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s1,s2;cin>>s1>>s2;
        if(s1==s2) {cout<<0<<'\n';continue;}
        int c0=0,c1=0;int c2=0,c3=0;
        for(int i=0;i<n;++i) {if(s1[i]!=s2[i]) {if(s1[i]=='0') ++c0; else ++c1;} else {if(s1[i]=='0') ++c2; else ++c3;}}
        int ans=f(c0,c1);
        if(c1!=0)
        {
            ans=min(ans,f(c3,c2+1)+1);
        }
        if(c3!=0)
        {
            ans=min(ans,f(c3-1,c2)+1);
        }
        if(ans>=1e9) cout<<(-1)<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}