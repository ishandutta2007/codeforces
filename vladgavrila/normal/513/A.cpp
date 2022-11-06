#include <cstdio>

using namespace std;

#define maxn 550

int d[maxn][maxn];
int n, m, k1, k2;

int main()
{
    scanf("%d%d", &n, &m);
    if(n>m)
        printf("First\n");
    else
        printf("Second\n");

    return 0;
}