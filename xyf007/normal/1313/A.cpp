#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, ans = 0;
        scanf("%d%d%d", &a, &b, &c);
        if (a > b)
        {
            swap(a, b);
        }
        if (a > c)
        {
            swap(a, c);
        }
        if (b > c)
        {
            swap(b, c);
        }
        if (a >= 4)
        {
            printf("7\n");
        }
        else
        {
            if (a == 3)
            {
                printf("6\n");
            }
            else
            {
                if (a == 2)
                {
                    if (c >= 3)
                    {
                        printf("5\n");
                    }
                    else
                    {
                        printf("4\n");
                    }
                }
                else
                {
                    if (a == 1)
                    {
                        if (b >= 2 && c >= 2)
                        {
                            printf("4\n");
                        }
                        else
                        {
                            printf("3\n");
                        }
                    }
                    else
                    {
                        if (b >= 2)
                        {
                            printf("3\n");
                        }
                        else
                        {
                            if (b)
                            {
                                printf("2\n");
                            }
                            else
                            {
                                if (c)
                                {
                                    printf("1\n");
                                }
                                else
                                {
                                    printf("0\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}