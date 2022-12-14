#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int arr[maxn];
bool vis[maxn];

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(int i=0,j=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        while(vis[arr[j]])j++;

        if(a!=arr[j])ans++;

        vis[a]=1;
    }

    printf("%d",ans);
    return 0;
}