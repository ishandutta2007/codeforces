#include <stdio.h>
#include <string.h>

using namespace std;

#define maxn 110

int n, ok, i, j, k, sum;
char v[maxn];
int sol[maxn], d[maxn][maxn][maxn];

void add(int a[], int b[], int c[])
{
    int aux[maxn];
    memset(aux, 0, sizeof(aux));
    int i, t=0;
    if(a[0]==0)
        a[0]=1;
    if(b[0]==0)
        b[0]=1;
    for(i=1; i<=a[0] || i<=b[0] || t>0; ++i, t/=10)
    {
        t=t+a[i]+b[i];
        aux[i]=t%10;
    }
    aux[0]=i-1;
    memset(c, 0, sizeof(c));
    for(int i=0; i<=aux[0]; ++i)
        c[i]=aux[i];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%s", v+1);
    n=strlen(v+1);
    for(int i=1; i<=n; ++i)
        v[i]-='0';
    for(int i=0; i<10; ++i)
        d[1][i][1]=d[1][i][0]=1;
    for(int i=1; i<n; ++i)
        for(int j=0; j<10; ++j)
        {
            sum=j+v[i+1];
            if(sum%2==0)
                add(d[i+1][sum/2], d[i][j], d[i+1][sum/2]);
            else
            {
                if(sum/2+1<10)
                    add(d[i+1][sum/2+1], d[i][j], d[i+1][sum/2+1]);
                add(d[i+1][sum/2], d[i][j], d[i+1][sum/2]);
            }
        }
    ok=1;
    for(int i=2; i<=n; ++i)
        if(v[i]>v[i-1]+1 || v[i]<v[i-1]-1)
            ok=0;
    for(int j=0; j<10; ++j)
        add(sol, d[n][j], sol);
    sol[1]=sol[1]-ok;
    for(int i=1; i<=sol[0]; ++i)
    {
        if(sol[i]>=0)
            break;
        sol[i]=9;
        sol[i+1]--;
    }
    if(sol[sol[0]]==0)
        sol[0]--;
    if(sol[0]==0)
        sol[0]++;
    for(int i=sol[0]; i; --i)
    {
        printf("%d", sol[i]);
    }
    return 0;
}