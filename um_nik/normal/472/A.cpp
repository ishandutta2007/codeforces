#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
bool p[1000100];
const int N = (int)1e6 + 4;

int main()
{

    for (int i = 2; i < N; i++)
        p[i] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!p[i])
            continue;
        for (int j = 2 * i; j < N; j += i)
            p[j] = 0;
    }
    cin >> n;
    for (int x = 3; x < n - 2; x++)
    {
        if (!p[x] && !p[n - x])
        {
            printf("%d %d\n", x, n - x);
            return 0;
        }
    }

    return 0;
}