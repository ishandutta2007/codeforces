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
    string s;
    cin>>s;
    int l[26];
    for(int i=0;i<26;++i) l[i]=0;
    for(int i=0;i<n;++i) l[s[i]-'a']++;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int x=__gcd(i,k);
        int y=i/x;
        int sum=0;
        for(int j=0;j<26;++j)
        {
            sum+=(l[j]/y)*y;
        }
        if(sum>=i)
        {
            ans=max(ans,i);
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}