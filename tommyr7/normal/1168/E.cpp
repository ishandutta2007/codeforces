#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int k,n;
int a[Maxn];
int now[Maxn],p[Maxn],q[Maxn],pos[Maxn];
void update(int i,int j)
{
    int k=pos[q[i]^now[i]];
    if (k==i) return;
    if (k==j)
    {
        swap(p[i],p[j]);
        swap(pos[p[i]],pos[p[j]]);
        return;
    }
    swap(pos[p[i]],pos[p[k]]);
    swap(p[i],p[k]);
    swap(q[j],q[k]);
    update(k,j);
}
int main()
{
    scanf("%d",&k);
    n=1<<k;
    int s=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s^=a[i];
    }
    if (s!=0)
    {
        printf("Fou\n");
        return 0;
    }
    printf("Shi\n");
    for (int i=0;i<n;i++)
    {
        p[i]=i;
        q[i]=i;
        pos[i]=i;
    }
    for (int i=0;i<n;i++)
        if (now[i]!=a[i])
        {
            int tmp=now[i]^a[i];
            now[i]^=tmp;
            now[i+1]^=tmp;
            update(i,i+1);
        }
    for (int i=0;i<n;i++)
        printf("%d ",p[i]);
    printf("\n");
    for (int i=0;i<n;i++)
        printf("%d ",q[i]);
    printf("\n");
    return 0;
}