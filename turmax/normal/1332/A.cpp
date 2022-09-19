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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    bool ans=true;
    int x3=(x+b-a);
    int y3=(y+d-c);
    ans=(x3<=x2 && x3>=x1 && y3<=y2 && y3>=y1);
    if(x1==x2 && (a!=0 || b!=0))
    {
        ans=false;
    }
    if(y1==y2 && (c!=0 || d!=0))
    {
        ans=false;
    }
    if(ans)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    }
    return 0;
}