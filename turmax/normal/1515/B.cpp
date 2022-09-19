#include <bits/stdc++.h>

using namespace std;
#define int long long
bool ok(int x)
{
    int o=((int) (sqrt(x)+0.5));
    return (o*o==x || (o-1)*(o-1)==x || (o+1)*(o+1)==x);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if((x%2==0 && ok(x)) || ok(2*x))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}