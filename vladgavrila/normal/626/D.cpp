#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 15110
#define maxd 5005

int n, m;
long long d[4][maxn];
int dif[maxn];
int v[maxn];
long long denom;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    sort(v+1, v+n+1);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<i; ++j)
            ++dif[v[i]-v[j]];

    int md=v[n]-v[1];

    d[0][maxd]=1;

    for(int pas=1; pas<=2; ++pas)
        for(int i=1; i<=md; ++i)
        {
            if(dif[i]>0)
            for(int pos=maxd; pos<=(pas-1)*md+maxd; ++pos)
                d[pas][pos+i]+=d[pas-1][pos]*dif[i];
        }

    int pas=3;
    for(int i=1; i<=md; ++i)
    {
        if(dif[i]>0)
        for(int pos=maxd; pos<=(pas-1)*md+maxd; ++pos)
            d[pas][pos-i]+=d[pas-1][pos]*dif[i];
    }

    long long sol = 0;

    for(int i=0; i<maxd; ++i)
        sol+=d[3][i];

    long long total = n*(n-1)/2;
    total = total*total*total;

    double x = double(sol)/total;

    printf("%.9lf\n", x);

    return 0;
}