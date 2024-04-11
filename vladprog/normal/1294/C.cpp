#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int t=n,x=0,y=0;
        for(int i=2;i*i<=n;i++)
            if(t%i==0)
            {
                if(!x)
                    x=i;
                else if(!y)
                    y=i;
                while(t%i==0)
                    t/=i;
            }
        if(t>1)
        {
            if(!x)
                x=t;
            else if(!y)
                y=t;
        }
        #define check(a,b,c) if(a>=2&&b>=2&&c>=2&&a!=b&&a!=c&&b!=c&&c*a*b==n) {cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n"; continue;}
        check(x,y,n/x/y);
        check(x,x*x,n/x/x/x);
        cout<<"NO\n";
    }
}