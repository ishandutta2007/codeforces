#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int n;
    int xl;
    int xr;
    int yl;
    int yr;
    int x,y;
    int a1,a2,a3,a4;
    int v;
    for(int i=0;i<q;++i)
    {
        v=1;
        xl=-1e5;
        yl=-1e5;
        xr=1e5;
        yr=1e5;
        cin>>n;
        for(int j=0;j<n;++j)
        {
            cin>>x>>y>>a1>>a2>>a3>>a4;
            if(a3==0)
            {
                if(xl>x)
                {
                    if(v==1)
                    {
                        cout<<0<<endl;
                    }
                    v=0;
                }
                else
                {
                    xr=min(xr,x);
                }
            }
            if(a1==0)
            {
                if(xr<x)
                {
                    if(v==1)
                    {
                        cout<<0<<endl;
                    }
                    v=0;
                }
                else
                {
                    xl=max(xl,x);
                }
            }
            if(a4==0)
            {
                if(yr<y)
                {
                    if(v==1)
                    {
                        cout<<0<<endl;
                    }
                    v=0;
                }
                else
                {
                    yl=max(yl,y);
                }
            }
            if(a2==0)
            {
                if(yl>y)
                {
                    if(v==1)
                    {
                        cout<<0<<endl;
                    }
                    v=0;
                }
                else
                {
                    yr=min(yr,y);
                }
            }
        }
        if(v==1)
        {
            if(xl<=xr && yl<=yr)
            {
                cout<<1<<" "<<xl<<" "<<yl<<endl;
            }
            else 
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}