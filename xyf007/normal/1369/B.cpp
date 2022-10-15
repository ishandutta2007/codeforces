#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
char s[100001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, s);
        int len1 = 0, len2 = 0;
        for (int i = 0; i < n && s[i] == '0'; i++)
        {
            len1++;
        }
        for (int i = n - 1; i >= 0 && s[i] == '1'; i--)
        {
            len2++;
        }
        if (len1 + len2 == n)
        {
            printf("%s", s);
        }
        else
        {
            for (int i = 0; i <= len1; i++)
            {
                printf("0");
            }
            for (int i = 0; i < len2; i++)
            {
                printf("1");
            }
        }
        printf("\n");
    }
    return 0;
}