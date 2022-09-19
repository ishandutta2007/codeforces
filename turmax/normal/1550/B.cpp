#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        if(b>0)
        {
            cout<<(a*n+b*n)<<'\n';
            continue;
        }
        else
        {
            int cnt=0;
            for(int i=1;i<n;++i) if(s[i]!=s[i-1]) ++cnt;
            ++cnt;
            cout<<(b*((cnt+2)/2)+a*n)<<'\n';
            continue;
        }
    }
    return 0;
}