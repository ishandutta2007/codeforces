#include<stdio.h>
#include<algorithm>
using namespace std;
int n,k,a[5010],cnt[5010],b[5010];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    sort(cnt+1,cnt+5001);
    if(cnt[5000]>k)
    {
        printf("NO");
        return 0;
    }
    int t=0;
    for(int i=1;i<=5000;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]==i)
            {
                b[j]=t%k+1;
                t++;
            }
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
}