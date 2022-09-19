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
        int n,k;
        cin>>n>>k;
        for(int i=0;i<(k-3);++i) cout<<1<<' ';
        n-=(k-3);
        int curr=1;
        bool ok=false;
        for(int i=3;i*i<=(2*n) && i<n;++i)
        {
            if(n%i==0)
            {
                curr=(n/i);
                n=i;
                ok=true;
                break;
            }
        }
        if(!ok)
        {
            if(n%2==0)
            {
                cout<<2<<' '<<(n-2)/2<<' '<<(n-2)/2<<endl;
            }
            else
            {
                cout<<1<<' '<<(n-1)/2<<' '<<(n-1)/2<<endl;
            }
        }
        else
        {
            if(n%2==0)
            {
                cout<<2*curr<<' '<<(n-2)/2*curr<<' '<<(n-2)/2*curr<<endl;
            }
            else
            {
                cout<<1*curr<<' '<<(n-1)/2*curr<<' '<<(n-1)/2*curr<<endl;
            }
        }
    }
    return 0;
}