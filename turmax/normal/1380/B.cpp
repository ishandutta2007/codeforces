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
        int r=0,h=0,p=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='R') ++r;
            if(s[i]=='P') ++p;
            if(s[i]=='S') ++h;
        }
        if(r>=h && r>=p)
        {
            for(int i=0;i<n;++i) cout<<'P';
            cout<<endl;
        }
        else if(h>=r && h>=p)
        {
            for(int i=0;i<n;++i) cout<<'R';
            cout<<endl;
        }
        else
        {
            for(int i=0;i<n;++i) cout<<'S';
            cout<<endl;
        }
    }
    return 0;
}