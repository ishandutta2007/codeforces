#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define P 1000000007
int n,m,S;
int a[10];
int f[10];
int ff2(int x)
{
    if(f[x]!=-1)return f[x];
    f[x]=0;
    return f[x]=ff2(a[x]);
}
bool can()
{
    memset(f,-1,sizeof f);
    f[1]=1;
    for(int i=2;i<=m;i++)
        if(ff2(i)==0)return 0;
    return 1;
}
void ff(int x)
{
    if(x==m+1){S+=can();return;}
    for(int i=1;i<=m;i++)
        a[x]=i,ff(x+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    ff(1);
    for(int i=m+1;i<=n;i++)
        S=(ll)S*(n-m)%P;
    printf("%d\n",S);
    return 0;
}