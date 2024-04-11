#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> del(int x)
{
    vector <int> v;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v.push_back(i);
            if(i*i!=x)
            {
                v.push_back(x/i);
            }
        }
    }
    sort(v.begin(),v.end());
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b;
    cin>>a>>b;
    vector <int> v1=del(a);vector <int> v2=del(b);
    int ans=1e18;
    int s=3;
    for(int i=1;i*i<=(a+b);++i)
    {
        if((a+b)%i==0)
        {
            int x=i;
            int y=(a+b)/i;
            int x1=*(--upper_bound(v1.begin(),v1.end(),x));
            int y1=*(--upper_bound(v1.begin(),v1.end(),y));
            if(x1*y1>=a)
            {
                ans=min(ans,2*x+2*y);
            }
            int x2=*(--upper_bound(v2.begin(),v2.end(),x));
            int y2=*(--upper_bound(v2.begin(),v2.end(),y));
            if(x2*y2>=b)
            {
                ans=min(ans,2*x+2*y);
            }
        }
    }
    cout<<ans;
    return 0;
}