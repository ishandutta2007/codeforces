#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;

int n;
ll k[3],t[3],arr[N],brr[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=0;i<3;i++)cin>>k[i];
    for(int i=0;i<3;i++)cin>>t[i];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        brr[i]=arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[j]+=t[i];
            if(j>=k[i])
            {
                arr[j]=max(arr[j],arr[j-k[i]]+t[i]);
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,arr[i]-brr[i]);
    cout<<ans;
    return 0;
}