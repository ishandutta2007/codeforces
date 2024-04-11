#include <bits/stdc++.h>

using namespace std;
#define int long long
int get(int x,int y,int a,int b,int u)
{
    if(x<(a*u) || y<(b*u) || u<0) return 0;
    return u+min((x-u*a)/b,(y-u*b)/a);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        int ans=0;
        ans=max(ans,get(x,y,a,b,(x/a)));ans=max(ans,get(x,y,a,b,(x/a)-1));
        ans=max(ans,get(x,y,a,b,(y/b)));ans=max(ans,get(x,y,a,b,(y/b)-1));
        ans=max(ans,get(x,y,a,b,0));
        if(a!=b) {ans=max(ans,get(x,y,a,b,((a*x-b*y)/(a*a-b*b))-1));ans=max(ans,get(x,y,a,b,((a*x-b*y)/(a*a-b*b))));ans=max(ans,get(x,y,a,b,((a*x-b*y)/(a*a-b*b)+1)));}
        cout<<ans<<'\n';
    }
    return 0;
}