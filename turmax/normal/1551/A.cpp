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
        if(n%3==0) {cout<<n/3<<' '<<n/3;}
        else if(n%3==1) {cout<<((n+2)/3)<<' '<<(n-1)/3;}
        else {cout<<(n-2)/3<<' '<<(n+1)/3;}
        cout<<endl;
    }
    return 0;
}