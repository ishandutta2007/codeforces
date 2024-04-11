#include <stdio.h>

using namespace std;

#define maxn 5010

char v[maxn][maxn];
int n, i, j, k, pt;
char mod[maxn][maxn];

char det(int x, int y, int nr)
{
    if(mod[x/nr][y/nr]=='*')
    {
        return '*';
    }
    else
    {
        if(nr==1)
            return '.';
        return det(x%nr, y%nr, nr/n);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", mod[i]);
    }
    pt=1;
    for(int i=1; i<=k; ++i)
        pt*=n;
    for(int i=0; i<pt; ++i)
    {
        for(int j=0; j<pt; ++j)
        {
            printf("%c", det(i, j, pt/n));
        }
        printf("\n");
    }
    return 0;
}