#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=2147493647;

int arr[maxn],n;
bool vis[maxn];

bool can()
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=i)return 0;
    }
    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            vis[arr[i]]=1;
        }

        if(!can())
        {
            puts("-1");
            fill(vis+1,vis+n+1,0);
            continue;
        }

        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                v.push_back(i);
        }

        for(int i=n-1,id=v.size()-1;i;i--)
        {
            if(arr[i]==arr[i-1])
            {
                arr[i]=v[id--];
            }
        }

        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        puts("");
        fill(vis+1,vis+n+1,0);
    }
    return 0;
}