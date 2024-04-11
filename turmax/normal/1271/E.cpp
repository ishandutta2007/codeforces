#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,t;
int po[62];
int check1(int x)
{
    int ans=0;
    //cout<<x<<" in check" <<endl;
    for(int i=0;i<62;++i)
    {
        //cout<<i<<" i ans "<<ans<<endl;
        if(x*po[i]>n)
        {
            break;
        }
        else if((x*po[i]+(po[i]-1))<=n)
        {
            ans+=po[i];
          //  cout<<po[i]<<" fcd "<<" "<<ans<<endl;
        }
        else
        {
            ans+=(n-x*po[i]+1);
            //cout<<(n-x*po[i]+1)<<" fds "<<endl;
        }
    }
    //cout<<ans<<" "<<x<<" ban "<<endl;
    return ans;
}
int check2(int x)
{
    if(x%2==0)
    {
        return check1(x)+check1(x+1);
    }
    else 
    {
        return check1(x);
    }
}
bool check(int x)
{
    return check2(x)>=t;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>t;
    int u=1;
    for(int i=0;i<62;++i)
    {
        po[i]=u;
        u*=2;
    }
    int l=1;
    int r=2*1e18;
    while(true)
    {
        if((r-l)==1)
        {
            cout<<l<<endl;
            return 0;
        }
        int k=(l+r)/2;
        if(check(max(k+1,1LL)) || check(k))
        {
            l=k;
        }
        else
        {
            r=k;
        }
    }
    return 0;
}