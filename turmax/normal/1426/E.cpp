#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    int b1,b2,b3;
    cin>>b1>>b2>>b3;
    int ans2=min(a1,b2)+min(a2,b3)+min(a3,b1);
    int ans1=max(max(0LL,a1+b2-n),max(a2+b3-n,a3+b1-n));
    cout<<ans1<<' '<<ans2;
    return 0;
}