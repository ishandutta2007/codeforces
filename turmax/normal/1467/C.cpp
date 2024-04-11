#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--)
    {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        int a[n1],b[n2],c[n3];
        int ans=0;
        int z[n1+n2+n3];
        int suma=0,sumb=0,sumc=0;
        for(int i=0;i<n1;++i) {cin>>a[i];ans+=a[i];z[i]=a[i];suma+=a[i];}
        for(int i=0;i<n2;++i) {cin>>b[i];ans+=b[i];z[i+n1]=b[i];sumb+=b[i];}
        for(int i=0;i<n3;++i) {cin>>c[i];ans+=c[i];z[i+n1+n2]=c[i];sumc+=c[i];}
        sort(a,a+n1);sort(b,b+n2);sort(c,c+n3);
        sort(z,z+n1+n2+n3);
        int res=0;
        if(n1==1) {res=max(res,ans-2*a[0]);}
        if(n2==1) {res=max(res,ans-2*b[0]);}
        if(n3==1) {res=max(res,ans-2*c[0]);}
        res=max(res,ans-2*suma);res=max(res,ans-2*sumb);res=max(res,ans-2*sumc);
        res=max(res,ans-2*a[0]-2*b[0]);res=max(res,ans-2*c[0]-2*b[0]);res=max(res,ans-2*a[0]-2*c[0]);
        cout<<res;
    }
    return 0;
}