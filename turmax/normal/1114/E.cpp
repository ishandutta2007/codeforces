#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    int n;
    cin>>n;
    int low=0,up=1e9;
    int k;
    int ans;
    while(true)
    {
        if((up-low)==1)
        {
            ans=up;
            break;
        }
        k=(low+up)/2;
        cout<<"> "<<k<<endl;
        int x;
        cin>>x;
        if(x)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
    int d=0;
    for(int i=0;i<30;++i)
    {
        int x=(rand()+32768*rand())%(n);
        cout<<"? "<<(x+1)<<endl;
        int y;
        cin>>y;
        if(y!=ans)
        d=__gcd(d,(ans-y));
    }
    cout<<"! "<<(ans-d*(n-1))<<" "<<d<<endl;
    return 0;
}