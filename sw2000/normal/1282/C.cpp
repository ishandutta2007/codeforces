#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;
const ll mod=1e9+7;
ll n,t,a,b;
struct Node
{
    ll a,b;
}arr[maxn];
bool cmp(Node x,Node y)
{
    if(x.b!=y.b)return x.b<y.b;
    return x.a<y.a;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        ll ans=0,cnt=0;
        scanf("%lld%lld%lld%lld",&n,&t,&a,&b);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&arr[i].a);
            if(arr[i].a==0)cnt++;
        }

        for(int i=0;i<n;i++)
            scanf("%lld",&arr[i].b);
        sort(arr,arr+n,cmp);
        arr[n].b=t+1;
        if(arr[0].b>a)
            ans=min((arr[0].b-1)/a,cnt);
        if(!arr[0].a)cnt--;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            if(arr[i-1].a)sum+=b;
            else sum+=a;


            if(arr[i].b>sum)
            {
                ll add=min((arr[i].b-sum-1)/a,cnt);
                ans=max(ans,i+add);
            }
            if(!arr[i].a)cnt--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}