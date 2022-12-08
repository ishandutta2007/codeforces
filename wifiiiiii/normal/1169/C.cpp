
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)
#define debug(i) cout<<#i<<":"<<i<<endl;

int a[300005],b[300005];
int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,n) cin>>a[i];
    int lo=0,hi=m;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        int ok = 1;
        rep(i,n)
        if(a[i]+mid>=m)
        {
            if(b[i-1]>a[i]+mid-m) b[i]=max(a[i],b[i-1]);
            else b[i]=b[i-1];
        }
        else
        {
            if(b[i-1]<=a[i]+mid) b[i]=max(b[i-1],a[i]);
            else ok = 0;
        }
        if(ok) hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<endl;
}