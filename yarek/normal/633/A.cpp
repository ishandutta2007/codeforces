#include <cstdio>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 0; i <= c; i += a)
        if((c - i) % b == 0)
        {
            puts("Yes");
            return 0;
        }
    puts("No");
}