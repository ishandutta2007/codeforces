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
    int n,k;
    cin>>n>>k;
    if(n>=(k*k) && (n-k)%2==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}