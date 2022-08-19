#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e6 + 100;
bool p[N];

int main()
{
    for (int i = 2; i < N; i++)
        p[i] = 1;
    for (int x = 2; x < N; x++)
    {
        if (!p[x]) continue;
        for (int y = 2 * x; y < N; y += x)
            p[y] = 0;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1;; i++)
    {
        if (!p[n * i + 1])
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}