#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--)
    {
        int n,r,p,s;
        string t;
        cin>>n>>r>>p>>s>>t;
        string ans;
        int cnt=0;
        for(char c:t)
        {
            if(c=='R')
            {
                if(p)
                    ans+='P',cnt++,p--;
                else
                    ans+='_';
            }
            if(c=='P')
            {
                if(s)
                    ans+='S',cnt++,s--;
                else
                    ans+='_';
            }
            if(c=='S')
            {
                if(r)
                    ans+='R',cnt++,r--;
                else
                    ans+='_';
            }
        }
        for(char&c:ans)
            if(c=='_')
                if(r)
                    c='R',r--;
                else if(p)
                    c='P',p--;
                else
                    c='S',s--;
        if(cnt>=(n+1)/2)
            cout<<"YES\n"<<ans<<"\n";
        else
            cout<<"NO\n";
    }
}