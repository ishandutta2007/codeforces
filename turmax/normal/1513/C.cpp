#include <bits/stdc++.h>

using namespace std;
const int p=1e9+7;
int o[2010000];
bool ok[2010000];
int go(int a,int b)
{
    int has=(10*b+a);
    if(b==0) return 1;
    if(ok[has]) return o[has];
    if(a!=9)
    {
        int ans=go(a+1,b-1);
        ok[has]=true;
        o[has]=ans;
        return ans;
    }
    else
    {
        int ans=go(1,b-1)+go(0,b-1);
        if(ans>=p) ans-=p;
        ok[has]=true;
        o[has]=ans;
        return ans;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int res=0;
        int n,m;
        cin>>n>>m;
        string s=to_string(n);
        for(auto h:s)
        {
            int x=h-'0';
            res+=go(x,m);
            res%=p;
        }
        cout<<res<<'\n';
    }
    return 0;
}