#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int arr[maxn];

int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    ll sum=0,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(i&1)cnt+=arr[i]>>1;
        else cnt+=arr[i]-(arr[i]>>1);
    }
    cout<<min(cnt,sum-cnt);
    return 0;
}