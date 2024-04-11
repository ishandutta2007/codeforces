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
        set <char> o;
        for(auto h:s) o.insert(h);
        if(o.size()==1 || (o.size()==2 && o.count('-')))
        {
            cout<<n<<endl;
            continue;
        }
        bool is[n];
        int ans=0;
        for(int i=0;i<n;++i)
        {
            is[i]=true;
            if(s[i]=='-' || s[(i+1)%n]=='-')
            {
                ++ans;
                continue;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}