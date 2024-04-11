#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int n,x,y;
        cin>>n>>x>>y;
        int mi,ma;
        if((x+y)<=n)
        {
            mi=1;
        }
        else
        {
            mi=(1+(x+y-n));
        }
        mi=min(mi,n);
        if((x+y)>n)
        {
            ma=n;
        }
        else
        {
            ma=(x+y-1);
        }
        cout<<mi<<" "<<ma<<endl;
    }
    return 0;
}