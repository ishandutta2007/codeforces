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
int n, p[1111], go[1111][1111], modulo = 1000000007;
void calc(int i, int j)
{
    if(go[i][j] != -1) return;
    if(i == j) {go[i][j] = 0; return;}
    calc(p[i], i);
    calc(i + 1, j);
    go[i][j] = (go[p[i]][i] + 2 + go[i + 1][j]) % modulo;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    memset(go, -1, sizeof(go));
    /*
    for(int i = 1; i <= n + 1; i++) go[i][i] = 0;
    for(int delta = 1; delta <= n; delta++)
    {
        for(int i = 1; i + delta <= n + 1; i++)
        {
            go[i][i + delta] = go[p[i]][i] + 2 + go[i + 1][i + delta];
        }
    }*/
    calc(1, n + 1);
    printf("%d\n", go[1][n + 1]);
    fclose(stdin);
    return 0;
}