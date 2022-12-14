#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1010
int n,m,a[N][N],b[N][N],k,S[N][N];
char s[N];
void rd()
{
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m-1;j++)
            a[i][j]=(s[j]=='N');
        if(i==n-1)break;
        scanf("%s",s);
        for(int j=0;j<m;j++)
            b[i][j]=(s[j]=='N');
    }
}
void rrd()
{
    for(int i=0;i<m;i++)
    {
        scanf("%s",s);
        for(int j=0;j<n-1;j++)
            b[j][i]=(s[j]=='N');
        if(i==m-1)break;
        scanf("%s",s);
        for(int j=0;j<n;j++)
            a[j][i]=(s[j]=='N');
    }
}
void pt()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            printf("%d%c",S[i][j]+1,j==m-1?'\n':' ');
}
void ppt()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            printf("%d%c",S[j][i]+1,j==n-1?'\n':' ');
}
void ff1()
{
    rd();
    int S=0,T=n*(m-1)+m*(n-1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m-1;j++)
            if(a[i][j]==0)S++;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m;j++)
            if(b[i][j]==0)S++;
    if(4*S>=3*T)
    {
        puts("YES");
        pt();
    }else puts("NO");
}
void ff()
{
    S[0][0]=0;
    for(int i=1;i<m;i++)
        S[0][i]=S[0][i-1]^a[0][i-1];
    for(int i=1;i<n;i++)
    {
        S[i][0]=0;
        for(int j=1;j<m;j++)
            S[i][j]=S[i][j-1]^a[i][j-1];
        int T=0;
        for(int j=0;j<m;j++)
            T+=(1^S[i-1][j]^S[i][j]^b[i-1][j]);
        if(T<m-T)
        {
            for(int j=0;j<m;j++)
                S[i][j]=S[i][j]^1;
        }
    }
}
bool R=0;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(k==1){ff1();return 0;}
    if(n>m){R=1;swap(n,m);rrd();}else rd();
    ff();
    puts("YES");
    if(R)ppt();else pt();
    return 0;
}