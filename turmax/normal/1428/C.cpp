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
        reverse(s.begin(),s.end());
        int n=s.size();
        int u[n+1];
        u[0]=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='A')
            u[i+1]=u[i]+1;
            else
            u[i+1]=u[i]-1;
        }
        int ans=*max_element(u,u+n+1);
        if((ans%2)!=(n%2))
        {
            ++ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}