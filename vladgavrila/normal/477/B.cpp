#include <cstdio>

using namespace std;

int n, m;

int main()
{
    scanf("%d%d", &n, &m);

    printf("%d\n", (n*6-1)*m);
    for(int i=1; i<=n; ++i)
        printf("%d %d %d %d\n", (i*6-5)*m, (i*6-4)*m, (i*6-3)*m, (i*6-1)*m);\

    return 0;
}