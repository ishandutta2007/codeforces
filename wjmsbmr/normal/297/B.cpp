#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define N 100010
int a[N],b[N],p[N*2],L,n,m,k;
int A[N*2];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%d",a+i),p[L++]=a[i];
    for(int i=0;i<m;i++)scanf("%d",b+i),p[L++]=b[i];
    sort(p,p+L);
    L=unique(p,p+L)-p;
    for(int i=0;i<n;i++)
        A[lower_bound(p,p+L,a[i])-p]++;
    for(int i=0;i<m;i++)
        A[lower_bound(p,p+L,b[i])-p]--;
    int S=0;bool F=0;
    for(int i=L-1;i>=0;i--)
    {
        S+=A[i];
        if(S>0){F=1;break;}
    }
    puts(F?"YES":"NO");
    return 0;
}