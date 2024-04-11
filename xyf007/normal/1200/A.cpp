#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
bool a[11];
int main(int argc, char const *argv[])
{
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        char c = getchar();
        if (c == 'L')
        {
            for (int j = 0; j < 10; j++)
            {
                if (!a[j])
                {
                    a[j] = 1;
                    break;
                }
            }
        }
        else
        {
            if (c == 'R')
            {
                for (int j = 9; j >= 0; j--)
                {
                    if (!a[j])
                    {
                        a[j] = 1;
                        break;
                    }
                }
            }
            else
            {
                int x = c - '0';
                a[x] = 0;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i])
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    return 0;
}