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
    if(n<=30) cout<<"NO"<<endl;
    else if(n!=36 && n!=40 && n!=44) {cout<<"YES"<<endl;cout<<6<<' '<<10<<' '<<14<<' '<<n-30<<endl;}
    else {cout<<"YES"<<endl;cout<<6<<' '<<10<<' '<<15<<' '<<n-31<<endl;}
    }
    return 0;
}