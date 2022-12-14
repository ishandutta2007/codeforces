#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int k[3],bl[maxn],n=0,pre[maxn],lst[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    for(int i=0;i<3;i++)
    {
        scanf("%d",&k[i]);
        n+=k[i];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            int a;
            scanf("%d",&a);
            bl[a]=i+1;
        }
    }

//    for(int i=1;i<=n;i++)
//    {
//        cout<<bl[i]<<' ';
//    }
//    cout<<endl;

    int oth=0;
    for(int i=1;i<=n;i++)
    {
        if(bl[i]==2)
        {
            pre[i]=pre[i-1];
            oth++;
        }
        else if(bl[i]==1)
        {
            pre[i]=min(oth,pre[i-1]+1);
        }
        else if(bl[i]==3)
        {
            pre[i]=pre[i-1]+1;
            oth++;
        }
    }

    oth=0;
    for(int i=n;i;i--)
    {
        if(bl[i]==2)
        {
            lst[i]=lst[i+1];
            oth++;
        }
        else if(bl[i]==3)
        {
            lst[i]=min(oth,lst[i+1]+1);
        }
        else if(bl[i]==1)
        {
            lst[i]=lst[i+1]+1;
            oth++;
        }
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<pre[i]<<' '<<lst[i]<<endl;
//    }
    int ans=inf;
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,pre[i]+lst[i+1]);
    }
    cout<<ans;
}