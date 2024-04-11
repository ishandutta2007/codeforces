#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000010
#define INF 1000000007
int a[N],n,m,st[N],sn,st2[N],sn2;
int main()
{
    scanf("%d",&n);
    a[1]=INF;a[n+2]=-INF;
    for(int i=2;i<=n+1;i++)scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=1,x;i<=m;i++)
        scanf("%d",&x),a[x+1]=-a[x+1];
    for(int i=1;i<=n+2;i++)
        if(a[i]>0)st[++sn]=i;else
        {
            sn2=0;
            st2[++sn2]=i;
            while(sn2>=1)
            {
                if(sn==0){puts("NO");return 0;}
                if(a[st[sn]]==-a[st2[sn2]])sn--,sn2--;
                else st2[++sn2]=st[sn],a[st[sn]]=-a[st[sn]],--sn;
            }
        }
    puts("YES");
    for(int i=2;i<=n+1;i++)
        printf("%d%c",a[i],i==n+1?'\n':' ');
    return 0;
}