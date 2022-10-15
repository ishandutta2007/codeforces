#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n1, n2;
int main(int argc, char const *argv[])
{
    printf("?");
    for (int i = 1; i <= 100; i++)
    {
        printf(" %d", i);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d", &n1);
    printf("?");
    for (int i = 1; i <= 100; i++)
    {
        printf(" %d", i << 7);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d", &n2);
    printf("! %d", (n1 & 16256) + (n2 & 127));
    fflush(stdout);
    return 0;
}