#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int mod=2;
        int cur=0;
        while(mod<=(1<<30))
        {
            if(2*mod-cur<=2e9) {cout<<"? "<<mod-cur<<' '<<2*mod-cur<<endl;int ans;cin>>ans;if(ans%mod!=0) {cur+=(mod/2);}}
            else {cout<<"? "<<mod/2-cur<<' '<<3*mod/2-cur<<endl;int ans;cin>>ans;if(ans%mod==0) {cur+=(mod/2);}}
            mod*=2;
        }
        cout<<"! "<<cur<<endl;
    }
    return 0;
}
/*
1
5
1 2 1 2
*/