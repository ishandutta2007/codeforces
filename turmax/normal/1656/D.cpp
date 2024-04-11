#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        bool ok=false;
        int n1=n;while(n1%2==0) n1/=2;
        if(n1!=1 && n1<2e9 && n1*(n1+1)/2<=n && (n-n1*(n1+1)/2)%n1==0)
            {
                cout<<n1<<endl;continue;
            }
        for(int k=2;;k*=2)
        {
            if(k*(k+1)/2>n)
            {
                cout<<(-1)<<endl;ok=true;break;
            }
            if((n-k*(k+1)/2)%k==0)
            {
                cout<<k<<endl;break;
            }
        }
        if(ok) continue;
    }
    return 0;
}