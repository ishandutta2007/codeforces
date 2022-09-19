#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int n;
    for(int i=0;i<q;++i)
    {
        cin>>n;
        if(n==1)
        {
            cout<<3<<endl;
        }
        else if(n==2)
        {
            cout<<2<<endl;
        }
        else
        {
            cout<<(n%2)<<endl;
        }
    }
    return 0;
}