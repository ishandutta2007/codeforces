#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        char s[105];
        scanf("%s", s);
        int len = strlen(s);
        if (s == string(len, '0') || s == string(len, '1'))
        {
            printf("%s\n", s);
            continue;
        }
        
        for (int i = 0; i < len; i++) printf("01");
        printf("\n");
    }
}