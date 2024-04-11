#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<int> divs(int n)
{
    vector<int> v;
    for(int i=1;i*i<=n;++i) {if(n%i==0) {v.push_back(i);if(i*i!=n) v.push_back(n/i);}}
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int a,b,c,d;cin>>a>>b>>c>>d;
        vector<int> va=divs(a);vector<int> vb=divs(b);
        bool ok=false;
        for(int a1:va) for(int b1:vb)
        {
            if(ok) break;
            int o=a1*b1;int h=(a*b)/(a1*b1);
            int x=((a+o)/o)*o;int y=((b+h)/h)*h;
            if(x<=c && y<=d) {ok=true;cout<<x<<' '<<y<<'\n';}
        }
        if(!ok) {cout<<(-1)<<' '<<(-1)<<'\n';continue;}
    }
    return 0;
}