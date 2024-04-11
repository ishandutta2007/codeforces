#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,a,b;
    cin>>t>>a>>b;
    if(a==t)
    {
        if(b!=a) {cout<<0;return 0;}
        else if(t!=1) {cout<<2;return 0;}
        else {cout<<"inf";return 0;}
    }
    if(b==a) {cout<<1;return 0;}
    if(a<t || b<a) {cout<<0;return 0;}
    int v[100]={0};int cur=0;
    int sum=0;
    while(b!=0)
    {
        v[cur]=(b%a);sum+=v[cur];b/=a;++cur;
    }
    if(t==1 && sum==1)
    {
        cout<<1;
        return 0;
    }
    int val=0;int z=1;
    for(int i=0;i<100;++i)
    {
        if(v[i]>0 && z>(2e18/v[i])) {val=(-1);break;}
        val+=z*v[i];if(z>(2e18/t)) z=2e18; else z*=t;
    }
    if(val==a) {cout<<1;return 0;}
    else {cout<<0;return 0;}
    return 0;
}