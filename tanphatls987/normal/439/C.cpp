#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=100001;

int n,k,p,tmp,a[2][maxi],h[2]={0},c,i,d[maxi],b,top1,tmp2,top2,j;
int readfile()
{
    scanf("%d%d%d",&n,&k,&p);
    c=0;top1=0;top2=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        h[tmp%2]++;
        if (tmp%2) a[1][++top1]=tmp;else a[0][++top2]=tmp;
    }
    for(i=1;i<=top2;i++) a[1][top1+i]=a[0][i];
}
int main()
{
    readfile();
    if ((h[1]%2)!=((k-p)%2))
        {printf("NO");return 0;}
    if (h[1]<k-p){printf("NO");return 0;}
    if (2*(p-h[0])>h[1]-(k-p)) {printf("NO");return 0;}
    printf("YES\n");
    tmp=k-p;tmp2=p;
    for(i=1;i<=top1;i++)
    {
        if (tmp2+tmp==1)
        {
            printf("%d ",n-i+1);
            for(j=i;j<=n;j++) printf("%d ",a[1][j]);
            return 0;
        }
        if (!tmp) break;
        printf("1 %d\n",a[1][i]);
        tmp--;
    }

    for(j=i;j<=n;j++)
    {
        if (tmp2+tmp==1)
        {
            printf("%d ",n-j+1);
            for(i=j;i<=n;i++) printf("%d ",a[1][i]);
            return 0;
        }
        if (a[1][j]%2) {printf("2 %d %d\n",a[1][j],a[1][j+1]);j++;}
        else printf("1 %d\n",a[1][j]);
        tmp2--;
    }
}