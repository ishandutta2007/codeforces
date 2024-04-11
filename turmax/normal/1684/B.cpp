#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int a,b,c;cin>>a>>b>>c;
        if(a==b && b==c && c==a)
        {
            cout<<3*a<<' '<<2*a<<' '<<a<<'\n';
            continue;
        }
        if(a>c && b<a+c) {cout<<a<<' '<<a+b+c<<' '<<a+c<<'\n';}
        else if(b>a && c<a+b) {cout<<b+a<<' '<<b<<' '<<a+b+c<<'\n';}
        else {cout<<a+b+c<<' '<<b+c<<' '<<c<<'\n';}
    }
    return 0;
}