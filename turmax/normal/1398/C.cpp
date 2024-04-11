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
        string s;
        cin>>s;
        int a[n];
        for(int i=0;i<n;++i) a[i]=s[i]-'0';
        int pr[n+1];pr[0]=0;
        for(int i=0;i<n;++i)
        {
            pr[i+1]=pr[i]+a[i];
        }
        map <int,int> o;
        int ans=0;
        for(int i=0;i<=n;++i)
        {
            if(o.count(pr[i]-i))
            {
                ans+=o[pr[i]-i];
                o[pr[i]-i]++;
            }
            else
            {
                o[pr[i]-i]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}