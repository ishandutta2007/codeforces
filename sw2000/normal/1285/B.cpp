#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

ll arr[maxn];
int n;

bool solve()
{
    ll sum=0;
    for(int i=1;i<=n;i++)sum+=arr[i];
    for(int i=1;i<n;i++)
    {
        arr[i]+=arr[i-1];
        if(arr[i]<=0||arr[i]>=sum)return 0;
    }
    return 1;

}

int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",arr+i);
        if(solve())puts("YES");
        else puts("NO");
    }
    return 0;
}