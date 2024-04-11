#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1010;
int n;
bool a[N];

bool check(int x)
{
    int y = 2;
    while(x % y != 0) y++;
    while(x % y == 0) x /= y;
    return x == 1;
}

int main()
{
    for (int x = 2; x < N; x++)
        a[x] = check(x);
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (int)a[i];
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        if (a[i])
            printf("%d ", i);
    printf("\n");

    return 0;
}