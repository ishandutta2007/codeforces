#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    if (m - 1 >= n - m)
        printf("%d\n", m - 1);
    else
        printf("%d\n", m + 1);

    return 0;
}