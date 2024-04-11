#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int inv2=(p+1)/2;
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<min((int) 4e6,m+1);++i)
    {
        ans+=(n%i);
    }
    ans%=p;
    for(int i=0;i<4e6;++i)
    {
         int l=(n/(i+1)+1);
         int r;
         if(i==0) r=m;
         else r=(n/i);
         r=min(r,m);
         l=max(l,(int) 4e6);
         if(r>=l)
         {
             ans+=(n%p)*((r-l+1)%p);
             ans%=p;
             r%=p;l%=p;
             int h=r*(r+1)-l*(l-1);
             h%=p;
             h*=i;
             h%=p;
             h*=inv2;
             h%=p;
             ans-=h;
             ans%=p;
         }
    }
    cout<<(ans%p+p)%p;
    return 0;
}