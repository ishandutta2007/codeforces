#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        int s=a+b+c+n;
        if(s%3)
        {
            cout<<"NO\n";
            continue;
        }
        s/=3;
        if(s>=a&&s>=b&&s>=c)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}