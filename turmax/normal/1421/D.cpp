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
        int x,y;
        cin>>x>>y;
        int c1,c2,c3,c4,c5,c6;
        cin>>c1>>c2>>c3>>c4>>c5>>c6;//c1:++x,++y,c2:++y,c3:--x,c4:--x,--y,c5:--y,c6:++x
        int ans=4e18;
        int ans1=0;
        if(x<=0)
        {
            ans1+=c3*(-x);
        }
        else
        {
            ans1+=c6*x;
        }
        if(y<=0)
        {
            ans1+=c5*(-y);
        }
        else
        {
            ans1+=c2*y;
        }
        ans=min(ans,ans1);
        ans1=0;
        if((x-y)<=0)
        {
            ans1+=c3*(-x+y);
        }
        else
        {
            ans1+=c6*(x-y);
        }
        if(y<=0)
        {
            ans1+=c4*(-y);
        }
        else
        {
            ans1+=c1*y;
        }
        ans=min(ans,ans1);
        ans1=0;
        if((y-x)<=0)
        {
            ans1+=c5*(-y+x);
        }
        else
        {
            ans1+=c2*(y-x);
        }
        if(x<=0)
        {
            ans1+=c4*(-x);
        }
        else
        {
            ans1+=c1*x;
        }
        ans=min(ans,ans1);
        cout<<ans<<endl;
    }
    return 0;
}