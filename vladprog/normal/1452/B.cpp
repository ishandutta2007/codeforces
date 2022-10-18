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
        int s=0,m=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            s+=a;
            m=max(m,a);
        }
        if(s>=m*(n-1))
            cout<<((n-1)-s%(n-1))%(n-1)<<"\n";
        else
            cout<<m*(n-1)-s<<"\n";
    }
}