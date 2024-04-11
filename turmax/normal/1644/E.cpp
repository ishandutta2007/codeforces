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
        int n;cin>>n;string s;cin>>s;
        int x=n,y=n;int c1=0,c2=0;
        for(auto h:s) if(h=='D') --x; else --y;
        //cout<<x<<" x "<<y<<" y "<<endl;
        //swap(x,y);
        int r=1;while(r<s.size() && s[r]==s[0]) ++r;
        int ans=(s[0]=='D' ? x+r : y+r);
        //cout<<ans<<" ans "<<endl;
        swap(x,y);
        for(auto h:s)
        {
            //cout<<ans<<" ans "<<endl;
            if(h=='D')
            {
                ++c1; if(c2 && c1==1) {ans+=x*y;continue;}
                if(c2) ans+=x;
            }
            else
            {
                ++c2;if(c1 && c2==1) {ans+=x*y;continue;}
                if(c1) ans+=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}