#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000007
#define N 510
int a[N][N],aw[N][N],n,p[N];
ll S[N];
int b[N][N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)scanf("%d",a[i]+j);
    for(int i=0;i<n;i++)scanf("%d",p+i),p[i]--;
    reverse(p,p+n);
    memcpy(aw,a,sizeof aw);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=aw[p[i]][p[j]];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)b[i][j]=a[i][j],b[j][i]=a[j][i];
        b[i][i]=0;
        for(int j=0;j<i;j++)
            for(int k=0;k<i;k++)
                b[i][k]=min(b[i][k],b[i][j]+b[j][k]),
                b[k][i]=min(b[k][i],b[k][j]+b[j][i]);
        if(i)S[i]=S[i-1];
        for(int j=0;j<i;j++)S[i]+=b[i][j]+b[j][i];
        for(int j=0;j<i;j++)
            for(int k=0;k<i;k++)
                if(b[j][i]+b[i][k]<b[j][k])
                {
                    S[i]-=b[j][k];
                    b[j][k]=b[j][i]+b[i][k];
                    S[i]+=b[j][k];
                }
    }
    reverse(S,S+n);
    for(int i=0;i<n;i++)
        printf("%I64d%c",S[i],i==n-1?'\n':' ');
    return 0;
}