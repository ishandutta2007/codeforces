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
        int w,h;
        cin>>h>>w;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int a=x2-x1;int b=y2-y1;
        //cout<<a<<' '<<b<<" a b "<<endl;
        int r1=max(x1,h-x2);int r2=max(y1,w-y2);
        //cout<<r1<<' '<<r2<<" r1 r2 "<<endl;
        int o1=(h-a);int o2=(w-b);
        int w1,h1;
        cin>>h1>>w1;
        bool ok=(o1>=h1 || o2>=w1);
        if(!ok) {cout<<(-1)<<'\n';continue;}
        int ans=1e18;
        if(o1>=h1) ans=min(ans,h1-r1);if(o2>=w1) ans=min(ans,w1-r2);
        ans=max(ans,0LL);
        cout<<setprecision(25)<<(ans+0.0)<<'\n';
    }
    return 0;
}