#include <bits/stdc++.h>

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

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int x1;
        cin>>x1;
        int g=0;
        for(int i=2;i<=n;i++)
        {
            int xi;
            cin>>xi;
            g=__gcd(g,abs(x1-xi));
        }
        if(x1==k)
            cout<<"YES\n";
        else if(g==0)
            cout<<"NO\n";
        else if((k-x1)%g==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}