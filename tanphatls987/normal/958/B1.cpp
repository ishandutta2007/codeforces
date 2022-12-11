#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000 + 2;

int n, d[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; scanf("%d %d", &u, &v);
        ++d[u], ++d[v];
    }
    printf("%d", count(d + 1, d + 1 + n, 1));
    return 0;
}