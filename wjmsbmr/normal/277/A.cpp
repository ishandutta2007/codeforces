#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 110
int n,m;
bool a[N][N];
int f[N];
int fa(int x)
{
    return x==f[x]?x:(f[x]=fa(f[x]));
}
int main()
{
    scanf("%d%d",&n,&m);
    bool F=0;
    memset(a,0,sizeof a);
    for(int i=0;i<n;i++)
    {
        int k;scanf("%d",&k);
        if(k>0)F=1;
        for(int j=0,x;j<k;j++)
        {
            scanf("%d",&x);
            a[i][x-1]=1;
        }
    }
    if(!F)
    {
        printf("%d\n",n);
        return 0;
    }
    for(int i=0;i<n;i++)f[i]=i;
    int S=n;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(fa(i)==fa(j))continue;
            bool F=0;
            for(int k=0;k<m;k++)
                if(a[i][k]&&a[j][k])F=1;
            if(F)f[fa(i)]=fa(j),S--;
        }
    printf("%d\n",S-1);
    return 0;
}