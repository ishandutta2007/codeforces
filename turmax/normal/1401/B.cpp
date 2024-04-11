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
    int x1,y1,z1;
    int x2,y2,z2;
    cin>>x1>>y1>>z1;
    cin>>x2>>y2>>z2;
    if(x1>=z2) {x1-=z2;z2=0;}
    else {z2-=x1;x1=0;}
    if(y1>=x2) {y1-=x2;x2=0;}
    else {y1=0;x2-=y1;}
    if(z2<y1 && z1>y2)
    {
        int o=min(z2,z1-y2);
        z2-=o;
        z1-=o;
    }
    cout<<2*min(z1,y2)-2*min(z2,y1)<<endl;
    }
    return 0;
}