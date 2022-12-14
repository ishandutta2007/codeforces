#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int arr[maxn],c[maxn],n;
int lb(int a)
{
    return a&(-a);
}

void add(int a)
{
    for(int i=a;i<=n;i+=lb(i))
        c[i]++;
}

int query(int a)
{
    int ret=0;
    for(int i=a;i;i-=lb(i))
    {
        ret+=c[i];
    }
    return ret;
}

int solve(int a)
{
    int l=0,r=n;
    while(l+1!=r)
    {
        int mid=l+r>>1;
        int v=query(mid);
        if(v>=a)r=mid;
        else l=mid;
    }
    return r;
}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        arr[a]=i;
    }
//    for(int i=1;i<=n;i++)
//        cout<<arr[i]<<' ';
//    cout<<endl;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=query(arr[i]);
        int r=i-l-1;
        add(arr[i]);
        ans+=r-min(r,l);
        int mid=i/2;
        if(i&1)mid++;
        else
        {
            if(l<r)mid++;
        }

//        cout<<ans<<endl;
//        cout<<mid<<' '<<solve(mid)<<endl;
        ans+=abs(solve(mid)-arr[i])-abs(mid-l-1);
        printf("%lld ",ans);
    }
    return 0;
}