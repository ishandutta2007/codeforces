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
        string ans;
        for(int i=0;i<s.size();i+=2)
        {
            ans+=s[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}