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
        int n;
        cin>>n;
        //(b=(a*a-1)/2)
        //(a*a+1)/2<=n
        cout<<((int) sqrt(2*n-1)-1)/2<<endl;
    }
    return 0;
}