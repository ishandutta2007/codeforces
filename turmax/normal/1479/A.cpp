#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
int getans(int x)
{
    if(x==n || x==(-1)) return 1e18;
    cout<<"? "<<x+1<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    int l=0,r=n;
    while(true)
    {
        if((r-l)==1)
        {
            cout<<"! "<<(l+1);
            return 0;
        }
        int m=(l+r)/2;
        int ans1=getans(m);
        int ans2=getans(m-1);
        int ans3=getans(m+1);
        if(ans1<ans2 && ans1<ans3)
        {
            cout<<"! "<<(m+1);
            return 0;
        }
        if(ans1>=ans2)
        {
            r=m;
        }
        else
        {
            l=m;
        }
    }
    return 0;
}