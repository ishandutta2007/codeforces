#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int q;
    cin>>q;
    int n;
    for(int j=0;j<q;++j)
    {
        cin>>n;
        cout<<1;
        cout<<3<<3;
        while(n%(100*201)!=0)
        {
            cout<<7;
            n--;
        }
        for(int i=0;i<199;++i)
        {
            cout<<3;
        }
        for(int i=0;i<(n/(100*201));++i)
        {
            cout<<7;
        }
        cout<<endl;
    }
    return 0;
}