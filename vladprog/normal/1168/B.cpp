#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
#define ld long double

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int l=0;l<n;l++)
    {
        int r=l;
        while(r<n)
        {
            bool ok=false;
            for(int k=1;r-2*k>=l;k++)
                if(s[r]==s[r-k]&&s[r]==s[r-2*k])
                {
                    ok=true;
                    break;
                }
            if(ok)
                break;
            r++;
        }
        ans+=n-r;
    }
    cout<<ans;
}