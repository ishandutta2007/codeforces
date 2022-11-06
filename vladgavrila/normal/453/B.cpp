#include <cstdio>

using namespace std;

#define maxn 110
#define msize 60
#define inf 1000000000

int n, v[maxn];
const int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
const int nprimes = 17;
int d[1<<nprimes][maxn], st[1<<nprimes][maxn];
int mask[msize];
int sol[maxn];

int ab(int a)
{
    if(a<0)
        return -a;
    return a;
}

int main()
{
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);

    scanf("%d", &n);

    for(int i=0; i<n; ++i)
        scanf("%d", &v[i]);

    for(int i=1; i<msize; ++i)
        for(int j=0; j<nprimes; ++j)
            if(i%primes[j]==0)
                mask[i]+=(1<<j);

 //   for(int i=1; i<msize; ++i)
     //   printf("%d\n", mask[i]);

    for(int i=0; i<(1<<nprimes); ++i)
        for(int j=0; j<=n; ++j)
            d[i][j]=inf;

    d[0][0]=0;

    for(int i=0; i<(1<<nprimes); ++i)
        for(int j=0; j<n; ++j)
        {
            if(d[i][j]==inf)
                continue;
            //    printf("*");
            for(int k=1; k<msize; ++k)
                if((mask[k]&i)==0)
                {
               //     printf("!%d\n", d[i|mask[k]][j+1]);
                    if(d[i|mask[k]][j+1]>d[i][j]+ab(v[j]-k))
                    {
                   //     printf("*");
                        d[i|mask[k]][j+1]=d[i][j]+ab(v[j]-k);
                        st[i|mask[k]][j+1]=k;
                    }
                }
        }

    int str=0;

    for(int i=1; i<(1<<nprimes); ++i)
        if(d[i][n]<d[str][n])
            str=i;

    for(int i=n; i; --i)
    {
        sol[i]=st[str][i];
        str-=mask[st[str][i]];
    }

    for(int i=1; i<=n; ++i)
        printf("%d ", sol[i]);
    printf("\n");

    return 0;
}