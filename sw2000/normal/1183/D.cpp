#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
int dis[maxn]={0},sum[maxn]={0};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            dis[a]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(dis[i]!=0)sum[dis[i]]++;
        }
        for(int i=n;i;i--)
        {
            cnt+=sum[i];
            if(cnt)
            {
                ans+=i;
                cnt--;
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=n;i++)
        {
            dis[i]=0;
            sum[i]=0;
        }
    }
    return 0;
}