#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000010
int n,a[N];
void add(int x,int y)
{
    a[x]=y,
    a[y]=n-x+1,
    a[n-x+1]=n-y+1,
    a[n-y+1]=x;
}
int main()
{
    scanf("%d",&n);
    if(n%4==2||n%4==3)puts("-1");else
    {
        for(int i=1;i<=n/2;i+=2)
            add(i,i+1);
        if(n%4==1)a[n/2+1]=n/2+1;
        for(int i=1;i<=n;i++)
            printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}