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
        int n,k;
        cin>>n>>k;
    int z=(n/k);
    int r=k-(k/2);
    cout<<min((z*r+(z+1)*(k-r)),n)<<endl;
    }
    return 0;
}