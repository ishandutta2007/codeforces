#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int sold[maxn];
int n,m,k,t;

struct A
{
    int l,r,d;
}arr[maxn];

int c[maxn];

bool can(int a)
{
    int l=inf,r=-inf;
    memset(c,0,sizeof(c));
    for(int i=0;i<k;i++)
    {
        if(arr[i].d>a)
        {
            c[arr[i].l]++;
            c[arr[i].r+1]--;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        c[i]+=c[i-1];
        if(c[i])sum++;
    }
    if(sum>t)return 0;
    else return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);

    cin>>m>>n>>k>>t;
    for(int i=0;i<m;i++)
        scanf("%d",&sold[i]);

    for(int i=0;i<k;i++)
    {
        scanf("%d%d%d",&arr[i].l,&arr[i].r,&arr[i].d);
    }

    t-=n+1;
    t/=2;
    int l=0,r=maxn;
    while(l+1!=r)
    {
        int mid=l+r>>1;
        if(can(mid))r=mid;
        else l=mid;
    }

    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(sold[i]>=r)ans++;
    }
    printf("%d",ans);
    return 0;
}