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
    string s;
    cin>>s;
    int n=s.size();
    int nex1[n+1];int nex2[n+1];int nex3[n+1];
    nex1[n]=1e9;nex2[n]=1e9;nex3[n]=1e9;
    int ans=1e9;
    for(int i=(n-1);i>=0;i--)
    {
        nex1[i]=nex1[i+1];nex2[i]=nex2[i+1];nex3[i]=nex3[i+1];
        if(s[i]=='1')
        {
            nex1[i]=i;
            ans=min(ans,max(nex2[i],nex3[i])-i+1);
        }
        if(s[i]=='2')
        {
            nex2[i]=i;
            ans=min(ans,max(nex1[i],nex3[i])-i+1);
        }
        if(s[i]=='3')
        {
            nex3[i]=i;
            ans=min(ans,max(nex2[i],nex1[i])-i+1);
        }
    }
    if(ans<=n)
    cout<<ans<<endl;
    else
    cout<<0<<endl;
    }
    return 0;
}