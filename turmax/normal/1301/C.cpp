#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,m;
    cin>>n>>m;
    m=(n-m);
    int x=(n-m+1);
    int t1=(m/x);
    int t2=(t1+1);
    int c1=(x-m%x);
    int c2=(m%x);
    int ans=(n*(n+1)/2);
    ans-=(c1*(t1*(t1+1)/2));
    ans-=(c2*(t2*(t2+1)/2));
    cout<<ans<<endl;
    }
    return 0;
}