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
        int a,b,n;
        cin>>a>>b>>n;
        int ans=1;
        while(a%2==0) {ans*=2;a/=2;}
        while(b%2==0) {ans*=2;b/=2;}
        if(ans>=n) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}