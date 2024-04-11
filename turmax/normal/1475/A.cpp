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
        while(n%2==0) n/=2;
        if(n==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}