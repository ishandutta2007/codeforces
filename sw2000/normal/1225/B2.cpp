#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

int vis[maxn],arr[200010];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,d;
        scanf("%d%d%d",&n,&k,&d);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int ans=inf,cnt=0;
        for(int i=0;i<d;i++)
        {
            if(!vis[arr[i]])
            {
                cnt++;
            }
            vis[arr[i]]++;
        }
        ans=min(ans,cnt);
        for(int l=0,r=d;r<n;r++,l++)
        {
            vis[arr[l]]--;
            if(!vis[arr[l]])cnt--;
            if(!vis[arr[r]])cnt++;
            vis[arr[r]]++;
            ans=min(ans,cnt);
        }
        for(int i=n-d;i<n;i++)
            vis[arr[i]]--;
        printf("%d\n",ans);
    }

    return 0;
}