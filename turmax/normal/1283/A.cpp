#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int cyc=0;cyc<q;++cyc)
    {
        int a,b;
        cin>>a>>b;
        cout<<(24-a)*60-b<<endl;
    }
    return 0;
}