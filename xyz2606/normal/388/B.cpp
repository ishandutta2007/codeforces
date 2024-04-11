#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int n, k;
bool f[1111][1111];
vector<int> nn[1111][20];
int main()
{
    scanf("%d", &k);
    memset(f, false, sizeof(f));
    n = 2;
    for(int i = 0; i <= 18; i++)
    {
        nn[i][0].push_back(1);
        for(int j = 1; j <= 18; j++) 
            for(int k = 1; k <= (j <= i?3:1); k++)
                nn[i][j].push_back(++n);
        nn[i][19].push_back(++n);
        nn[i][19].push_back(++n);
        for(int j = 1; j <= 19; j++) for(int k1 = 0; k1 < (int)nn[i][j].size(); k1++)
            for(int k2 = 0; k2 < (int)nn[i][j - 1].size(); k2++)
                f[nn[i][j][k1]][nn[i][j - 1][k2]] = true;
    }
    printf("%d\n", n);
    for(int i = 0, x = 1; i <= 18; i++, x *= 3)
    {
        for(int j = (k % (3 * x)) / x - 1; j >= 0; j--) f[nn[i][19][j]][2] = true;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = f[j][i] = f[i][j] | f[j][i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) printf("%c", f[i][j]?'Y':'N');
        printf("\n");
    }
    return 0;
}