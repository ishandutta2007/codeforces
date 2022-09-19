#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
    int a,n;
    cin>>a>>n;
    n--;
    bool h=true;
    for(int i=0;i<n;++i)
    {
        int sym;
        int mi=1e18;
        int ma=(-1);
        int x=a;
        while(x!=0)
        {
            sym=(x%10);
            mi=min(mi,sym);
            ma=max(ma,sym);
            x/=10;
        }
        a+=(mi*ma);
        if(mi==0)
        {
            cout<<a<<endl;
            h=false;
            break;
        }
    }
    if(h)
    {
        cout<<a<<endl;
        continue;
    }
    }
    return 0;
}