#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=4e5+10;
int arr[maxn],brr[maxn],ans=-inf,cnt=0;

int main()
{
    int two[31];
    two[0]=1;
    for(int i=1;i<31;i++)two[i]=two[i-1]*2;
    int n,m;
    cin>>n>>m;
    m=m*8/n;
    if(m>30)
    {
        cout<<0;
        return 0;
    }
    m=two[m];


    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    brr[0]=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            brr[i]=++cnt;
        }
        else
        {
            brr[i]=brr[i-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        ans=max(ans,upper_bound(brr+i,brr+n,brr[i]+m-1)-brr-i);
    }
    cout<<n-ans;
    return 0;
}