#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int Q, n, m;
char st[3333], a[3001][3001];
long long f[3001][3001], modulo = 1000000007;
long long calc(int i1, int j1, int i2, int j2)
{
    memset(f, 0, sizeof(f));
    for(int i = i1; i <= i2; i++) 
        for(int j = j1; j <= j2; j++)
        {
            if(a[i][j] == '#')
            {
                f[i][j] = 0;
            }else if(i == i1 or j == j1)
            {
                if(i == i1 and j == j1) f[i][j] = 1;
                else if(i == i1) f[i][j] = f[i][j - 1];
                else f[i][j] = f[i -1][j];
            }else
            {
                f[i][j] = (f[i - 1][j] + f[i][j - 1]) % modulo;
            }
        }
    //printf("%I64d\n", f[i2][j2]);
    return f[i2][j2];
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", st);
        for(int j = 0; j < m; j++) a[i][j + 1] = st[j];
    }
    printf("%I64d\n", ((calc(1, 2, n - 1, m) * calc(2, 1, n, m - 1) - calc(1, 2, n, m - 1) * calc(2, 1, n - 1, m)) % modulo + modulo) % modulo);
    fclose(stdin);
    return 0;
}