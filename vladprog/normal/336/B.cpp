#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ld r;
    int m;
    cin>>m>>r;
    ld ans=m*2+2*(m-1)*(2+sqrt(2));
    for(int d=2;d<=m-1;d++)
        ans+=2*(m-d)*(2*d-2+2*sqrt(2));
    cout<<fixed<<setprecision(10)<<ans/(m*m)*r;
}