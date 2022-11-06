#include <cstdio>

using namespace std;

int main()
{
    printf("%d\n", 2001);
    for(int i=1; i<=1000; ++i)
        printf("%d %d %d %d\n", i, 1, i, 2);
    for(int i=1; i<=1; ++i)
        printf("%d %d %d %d\n", i, 1, i, 2);
    for(int i=1; i<=1000; ++i)
        printf("%d %d %d %d\n", i, 1, i, 2);
    return 0;
}