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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a>(b*c))
        {
            cout<<(-1)<<endl;
            continue;
        }
        int k=(a/(d*b));
        cout<<(a*(k+1))-(d*b*k*(k+1)/2)<<endl;
    }
    return 0;
}