#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int arr[maxn];

int main()
{
    int n,m;
    ll ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int l=0,r=0;l<n;l++)
    {
        while(r!=n-1&&arr[r+1]-arr[l]<=m)r++;
        int len=r-l;
        ans+=(ll)len*(len-1)/2;
    }
    cout<<ans;
    return 0;
}