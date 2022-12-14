#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll arr[maxn],brr[maxn],n,m;
vector<int>v;

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    sort(arr+1,arr+n+1);
//    for(int i=1;i<=n;i++)
//    {
//        printf("%lld ",arr[i]);
//    }
//    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        arr[i]+=arr[max((ll)0,i-m)];
    }
//    for(int i=1;i<=n;i++)
//    {
//        printf("%lld ",arr[i]);
//    }
//    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        arr[i]+=arr[i-1];
        printf("%lld ",arr[i]);
    }
    return 0;
}