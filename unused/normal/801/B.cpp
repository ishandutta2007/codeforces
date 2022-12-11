#include <bits/stdc++.h>
using namespace std;

char a[105];
char b[105];

int main()
{
    scanf("%s%s",a,b);
    for (int i = 0; a[i]; i++)
    {
        if (a[i] < b[i])
        {
            printf("-1\n"); return 0;
        }
    }

    printf("%s\n", b);
}