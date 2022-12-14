#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;
const ll mod=1e9+7;
int arr[maxn],l[maxn],r[maxn],n;

int solve(int a)
{
    if(!a)return 0;
//    cout<<a<<endl;
    for(int i=1;i<=n;i++)
    {
        if(l[i]==1)l[i]=l[i-1]+1;
        else l[i]=l[i-1]-1;
//        cout<<l[i]<<' ';
    }
//    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(r[i]==1)r[i]=r[i-1]+1;
        else r[i]=r[i-1]-1;
//        cout<<r[i]<<' ';
    }
//    cout<<endl;

    int pre[maxn],ma=0;
    pre[0]=0;
    for(int i=n;i;i--)
    {
        if(l[i]>0)pre[l[i]]=i;
        ma=max(ma,l[i]);
    }
    int ret=inf;
    if(ma>=a)
    {
        ret=min(ret,pre[a]);
    }
    for(int i=1;i<=n;i++)
    {
        if(r[i]>0&&a-r[i]<=ma&&a-r[i]>=0)
        {
            ret=min(ret,i+pre[a-r[i]]);
        }
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        int cnt[3]={0};
        scanf("%d",&n);
        for(int i=1;i<=n*2;i++)
        {
            scanf("%d",arr+i);
            cnt[arr[i]]++;
        }
        if(cnt[1]<cnt[2])
        {
            for(int i=1;i<=n*2;i++)
            {
                arr[i]=3-arr[i];
            }
        }
        for(int i=n;i;i--)l[n-i+1]=arr[i];
        for(int i=n+1;i<=2*n;i++)r[i-n]=arr[i];
        printf("%d\n",solve(abs(cnt[1]-cnt[2])));
    }
    return 0;
}