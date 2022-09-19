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
        bool h=false;
        cin>>s;
        for(int i=0;i<s.size()-1;++i)
        {
            if(s[i]!=s[i+1])
            {
                h=true;
                cout<<i+1<<' '<<i+2<<endl;
                break;
            }
        }
        if(!h) cout<<(-1)<<' '<<(-1)<<endl;
    }
    return 0;
}