#include <bits/stdc++.h>

using namespace std;
#define int long long
double go1(vector <int> a,double m)
{
    int n=a.size();
    int v=1;
    int curr=0;
    for(int i=0;i<n;++i)
    {
        if(v*m>=(a[i]-curr))
        {
            m-=((a[i]-curr+0.0)/v);
            ++v;
            curr=a[i];
        }
        else
        {
            return curr+m*v;
        }
    }
    return curr+m*v;
}
double go2(vector <int> a,double m,int l)
{
    for(int i=0;i<a.size();++i)
    {
        a[i]=l-a[i];
    }
    reverse(a.begin(),a.end());
    double z=go1(a,m);
    return (l-z);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,l;
        cin>>n>>l;
        vector <int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        double low=0;
        double up=l;
        while((up-low)>=1e-7)
        {
            double m=(low+up)/2;
            double z1=go1(a,m);
            double z2=go2(a,m,l);
            if(z1>=z2)
            {
                up=m;
            }
            else
            {
                low=m;
            }
        }
        cout<<fixed<<setprecision(15)<<low<<endl;
    }
    return 0;
}