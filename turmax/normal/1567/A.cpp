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
        string h;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='U') h.push_back('D');
            else if(s[i]=='L') h.push_back('L');
            else if(s[i]=='R') h.push_back('R');
            else h.push_back('U');
        }
        cout<<h<<endl;
    }
    return 0;
}