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
    int l,r,m;
    cin>>l>>r>>m;
    int m2=m+r-l;
    int m1=max(1LL,m+l-r);
    for(int a=l;a<=r;++a)
    {
        {
            int n1=m/a;
            int n2=n1+1;
            if(abs(m-n1*a)<=(r-l) && (m-n1*a)<m)
            {
                int ans1=(m-n1*a);
                if(ans1>=0)
                {
                    cout<<a<<' '<<l+ans1<<' '<<l<<endl;
                    break;
                }
                else
                {
                    cout<<a<<' '<<l<<' '<<l-ans1<<endl;
                    break;
                }
            }
            if(abs(m-n2*a)<=(r-l) && (m-n2*a)<m)
            {
                int ans1=(m-n2*a);
                if(ans1>=0)
                {
                    cout<<a<<' '<<l+ans1<<' '<<l<<endl;
                    break;
                }
                else
                {
                    cout<<a<<' '<<l<<' '<<l-ans1<<endl;
                    break;
                }
            }
        }
    }
    }
    return 0;
}