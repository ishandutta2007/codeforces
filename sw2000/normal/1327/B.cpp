#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

bool solve()
{
    int n;scanf("%d",&n);
    int ans=-1;
    bool vis[maxn]={0};
    for(int i=0;i<n;i++)
    {
        int k,arr[maxn];
        scanf("%d",&k);
        if(k==0)ans=i+1;
        for(int j=0;j<k;j++)
        {
            scanf("%d",arr+j);
        }
        for(int j=0;j<k;j++)
        {
            if(!vis[arr[j]])
            {
                vis[arr[j]]=1;
                break;
            }
            else if(j==k-1)
            {
                ans=i+1;
            }
        }
    }
    if(ans==-1)
    {
        return 1;
    }
    else
    {
        puts("IMPROVE");
        printf("%d ",ans);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                printf("%d\n",i);
                return 0;
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())
        {
            puts("OPTIMAL");
        }
    }
	return 0;
}