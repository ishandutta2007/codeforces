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
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    cout<<min(abs(x-y)*a+min(abs(x),abs(y))*b,abs(x)*a+abs(y)*a)<<endl;
    }
    return 0;
}