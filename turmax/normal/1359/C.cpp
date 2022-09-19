#include <bits/stdc++.h>

using namespace std;
#define int long long
double f(double h,double c,double m,double t)
{
    return abs((h+c)/2.0+(h-c)/(4*m+2)-t);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int h,c,t;
    cin>>h>>c>>t;
    if(2*t<=(h+c))
    {
        cout<<2<<endl;
        continue;
    }
    int l=(-1);int r=1e9;
    while((r-l)>=3)
    {
        //cout<<l<<" "<<r<<" lr "<<endl;
        int m1=l+(r-l)/3;
        int m2=r-(r-l)/3;
        if(f(h,c,m1,t)<f(h,c,m2,t))
        {
            r=m2;
        }
        else
        {
            l=m1;
        }
    }
    //cout<<l<<" l "<<endl;
    int ans=(-1);
    double ans1=1e18;
    double u=f(h,c,l,t);
    if(l!=(-1) && u<ans1)
    {
        ans1=u;
        ans=l;
    }
    //cout<<l<<" l "<<endl;
    //cout<<ans1<<" ans1 "<<endl;
    ++l;
    u=f(h,c,l,t);
    if(l!=(-1) && u<ans1)
    {
        ans1=u;
        ans=l;
    }
    ++l;
    u=f(h,c,l,t);
    if(l!=(-1) && u<ans1)
    {
        ans1=u;
        ans=l;
    }
    cout<<2*ans+1<<endl;
    /*cout<<f(h,c,2,t)<<endl;
    for(int i=0;i<10;++i)
    {
        cout<<f(h,c,i,t)<<endl;
    }*/
    }
    return 0;
}