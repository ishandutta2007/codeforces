#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (isPrime(n))
    {
        printf("1\n%d\n", n);
        return 0;
    }
    if (isPrime(n - 2))
    {
        printf("2\n2 %d\n", n - 2);
        return 0;
    }
    if (isPrime(n - 4))
    {
        printf("3\n2 2 %d\n", n - 4);
        return 0;
    }
    for (int i = 3; 2 * i + 3 <= n; i += 2)
    {
        if (isPrime(i) && isPrime(n - 3 - i))
        {
            printf("3\n3 %d %d\n", i, n - 3 - i);
            return 0;
        }
    }
    throw;

    return 0;
}