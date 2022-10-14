#include <bits/stdc++.h>

using namespace std;
long double typedef ld;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    ld ans=0;
    for(int i=1;i<=n;i++)ans+=(1.0/(n-i+1));
    cout<<fixed<<setprecision(4)<<ans;
}