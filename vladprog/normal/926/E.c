#include <stdio.h>

int val[200010],prev[200010],next[200010];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&val[i]),prev[i]=i-1,next[i]=i+1;
    prev[0]=-1;
    next[n-1]=-1;
    int i=0;
    while(1)
    {
        while(next[i]!=-1&&val[i]!=val[next[i]])
            i=next[i];
        if(next[i]==-1)
            break;
        val[i]++;
        next[i]=next[next[i]];
        if(next[i]!=-1)
            prev[next[i]]=i;
        if(prev[i]!=-1)
            i=prev[i];
    }
    while(prev[i]!=-1)
        i=prev[i];
    int cnt=0;
    for(int j=i;j!=-1;j=next[j])
        cnt++;
    printf("%d\n",cnt);
    for(int j=i;j!=-1;j=next[j])
        printf("%d ",val[j]);
}