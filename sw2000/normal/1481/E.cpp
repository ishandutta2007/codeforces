#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
const int N=5e5+10;
const int inf=0x3f3f3f3f;
int n,ans,arr[N],sum[N],r[N],ma[N],lst[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        r[arr[i]]=i;
    }
    for(int i=n;i;i--)
    {
        sum[arr[i]]++;
        lst[i]=sum[arr[i]];
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,ma[i-1]+lst[i]);
        ma[i]=max(ma[i],ma[i-1]);
        if(r[arr[i]])ma[r[arr[i]]]=ma[i]+sum[arr[i]],r[arr[i]]=0;
    }
    cout<<n-ans;
    return 0;
}