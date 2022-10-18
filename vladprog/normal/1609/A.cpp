#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

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
        int s=0,m=0,t=1;
        while(n--)
        {
            int a;
            cin>>a;
            while(a%2==0)
                a/=2,t*=2;
            s+=a;
            m=max(m,a);
        }
        cout<<s-m+m*t<<"\n";
    }
}