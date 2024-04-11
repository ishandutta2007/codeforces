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
int n, x, y, dx, dy;
long long t, ans[6][6], tmp[6][6] = 
{
    {2, 1, 1, 0, 1, 2},
    {1, 2, 0, 1, 1, 2},
    {1, 1, 1, 0, 1, 2},
    {1, 1, 0, 1, 1, 2},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 1}
}, d[6][6];
int fuck(const long long & x)
{return (int)(x % n);}
void mul(const long long (&a)[6][6], const long long (&b)[6][6], long long (&c)[6][6])
{
    memset(d, 0, sizeof(d));
    for(int i = 0; i < 6; i++) for(int j = 0; j < 6; j++) for(int k = 0; k < 6; k++) d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % n;
    memcpy(c, d, sizeof(d));
}   
int main()
{
    scanf("%d%d%d%d%d%I64d", &n, &x, &y, &dx, &dy, &t);
    x--;
    y--;
    dx = (dx % n + n) % n;
    dy = (dy % n + n) % n;
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < 6; i++) ans[i][i] = 1 % n;
    while(t)
    {
        if(t & 1) mul(ans, tmp, ans);
        t /= 2;
        mul(tmp, tmp, tmp);
    }
    printf("%d %d\n", 1 + fuck(ans[0][0] * x + ans[0][1] * y + ans[0][2] * dx + ans[0][3] * dy + ans[0][5]), 1 + fuck(ans[1][0] * x + ans[1][1] * y + ans[1][2] * dx + ans[1][3] * dy + ans[1][5]));
    fclose(stdin);
    return 0;
}