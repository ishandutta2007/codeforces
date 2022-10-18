#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        int l=1e9,r=0;
        while(n--)
        {
            int a;
            cin>>a;
            l=min(l,a);
            r=max(r,a);
        }
        cout<<(r-l<=2*k?l+k:-1ll)<<"\n";
    }
}