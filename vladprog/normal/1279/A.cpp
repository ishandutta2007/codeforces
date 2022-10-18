#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int r,g,b;
        cin>>r>>g>>b;
        int mx=max({r,g,b});
        int el=r+g+b-mx;
        cout<<(mx-el<=1?"Yes\n":"No\n");
    }
}