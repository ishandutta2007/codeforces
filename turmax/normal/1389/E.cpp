#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int m,d,w;
    cin>>m>>d>>w;
    int u=w/__gcd(w,d-1);
    int o=min(m,d);
    if(u>=o)
    {
        cout<<0<<endl;
        continue;
    }
    int l1=(o/u);
    int l2=l1+1;
    int c1=(u-o%u);
    int c2=(u-c1);
    cout<<c1*((l1*(l1-1))/2)+c2*((l2*(l2-1))/2)<<endl;
    }
    return 0;
}