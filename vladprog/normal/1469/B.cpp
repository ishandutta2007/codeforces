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
        int mx1=0;
        int sum1=0;
        while(n--)
        {
            int x;
            cin>>x;
            mx1=max(mx1,sum1+=x);
        }
        int m;
        cin>>m;
        int mx2=0;
        int sum2=0;
        while(m--)
        {
            int x;
            cin>>x;
            mx2=max(mx2,sum2+=x);
        }
        cout<<mx1+mx2<<"\n";
    }
}