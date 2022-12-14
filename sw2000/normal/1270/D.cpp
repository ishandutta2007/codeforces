#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;
int arr[maxn],brr[maxn];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k+1;i++)
    {
        cout<<"?";
        for(int j=1;j<=k+1;j++)if(j!=i)
            cout<<" "<<j;
        cout<<endl;
        cin>>arr[i]>>brr[i];
    }
    int a=arr[1],aa=brr[1];
    int b=arr[a],bb=brr[a];
    if(aa>bb)swap(a,b);
    int ans=1;
    for(int i=1;i<=k+1;i++)if(i!=a&&i!=b)
    {
        if(arr[i]==b)ans++;
    }
    cout<<"! "<<ans<<endl;
    return 0;
}