#include <cstdio>

using namespace std;

#define maxn 1010

int n, d, k;
int sol[maxn][maxn];
int v[maxn];

int main()
{
    scanf("%d%d%d", &n, &k, &d);

    for(int i=2; i<=n; ++i)
    {
        int j=1;
        ++v[j];
        while(v[j]==k)
        {
            v[j]=0;
            ++v[j+1];
            ++j;
            if(j>d)
            {
                printf("-1\n");

                return 0;
            }
        }

        for(int l=1; l<=d; ++l)
            sol[i][l]=v[l];
    }

    for(int i=1; i<=d; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%d ", sol[j][i]+1);
        printf("\n");
    }
    return 0;
}