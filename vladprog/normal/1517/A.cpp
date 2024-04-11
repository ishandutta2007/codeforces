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
        int n;
        cin>>n;
        if(n%2050)
            cout<<-1<<"\n";
        else
        {
            n/=2050;
            int ans=0;
            while(n)
                ans+=n%10,n/=10;
            cout<<ans<<"\n";
        }
    }
}