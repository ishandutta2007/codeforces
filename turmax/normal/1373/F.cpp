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
        int n;
        cin>>n;
        int a[2*n];
        int b[2*n];
        int s1=0,s2=0;
        for(int i=0;i<n;++i) {cin>>a[i];a[i+n]=a[i];s1+=a[i];}
        for(int i=0;i<n;++i) {cin>>b[i];b[i+n]=b[i];s2+=b[i];}
        if(s1>s2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int pr[2*n+1];
        pr[0]=0;
        for(int i=0;i<2*n;++i)
        {
            pr[i+1]=pr[i]+a[i]-b[i];
        }
        int ma=(-1e18);
        bool h=false;
        for(int i=2*n;i>=0;i--)
        {
            int x=pr[i];ma=max(ma,x);
            //cout<<x<<" x "<<endl;
            if((ma-x)>b[(i+2*n-1)%n])
            {
                cout<<"NO"<<endl;
                h=true;
                break;
            }
        }
        if(!h)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}