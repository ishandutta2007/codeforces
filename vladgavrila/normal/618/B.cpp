#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 55

int n, m;
int p[maxn];
int v[maxn][maxn];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            scanf("%d", &v[i][j]);

    for(int i=1; i<n; ++i)
    {
        int cc;
        for(int j=1; j<=n; ++j)
        {
            if(p[j]>0)
                continue;
            int mxc=0;
            for(int k=1; k<=n; ++k)
                if(p[k]==0)
                    mxc=max(mxc, v[j][k]);

            if(mxc == i)
            {
                p[j] = i;
                break;
            }
        }
    }

    for(int i=1; i<=n; ++i)
        if(p[i]==0)
            printf("%d ", n);
        else
            printf("%d ", p[i]);

    return 0;
}