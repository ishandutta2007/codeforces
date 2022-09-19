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
        set <pair<int,int> > d;
        int nxt[n];
        for(int i=(n-1);i>=0;i--)
        {
            if(s[i]=='W')
            {
                nxt[i]=0;
            }
            else
            {
                if(i!=(n-1))
                nxt[i]=nxt[i+1]+1;
                else
                nxt[i]=1e18;
            }
        }
        for(int i=1;i<n;++i)
        {
            if(s[i]=='L' && s[i-1]=='W')
            {
                d.insert({nxt[i],i});
            }
        }
        if(s[0]=='L')
        {
            d.insert({2e18,0});
        }
        int cyc=0;
        while(!d.empty() && cyc<k)
        {
            pair <int,int> o=*d.begin();
            d.erase(d.begin());
            if(o.first==2e18)
            {
                for(int i=(n-1);i>=0 && cyc<k;--i)
                {
                    if(s[i]=='L')
                    {
                        s[i]='W';
                        ++cyc;
                    }
                }
                break;
            }
            ++cyc;
            int x=o.second;
            s[x]='W';
            if(x!=(n-1) && s[x+1]=='L')
            {
                d.insert({o.first-1,x+1});
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='W')
            {
                ++ans;
            }
            if(s[i]=='W' && i>=1 && s[i-1]=='W')
            {
                ++ans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}