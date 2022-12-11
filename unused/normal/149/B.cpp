#include <bits/stdc++.h>
using namespace std;

char s1[100], s2[100];
char sss[100];

int g(int ch)
{
    if (ch >= '0' && ch <= '9') return ch - '0';
    else return ch - 'A' + 10;
}

int conv(const char *str, int radix)
{
    int ret = 0;
    for (int i = 0; str[i]; i++)
    {
        ret = ret * radix + g(str[i]);
    }
    return ret;
}

int main()
{
    scanf("%s",sss);
    strcpy(s1, strtok(sss, ":"));
    strcpy(s2, strtok(nullptr, ":"));

    int minradix = max(*max_element(s1,s1+strlen(s1)), *max_element(s2,s2+strlen(s2)));
    if (minradix >= 'A') minradix = minradix - 'A' + 11;
    else minradix = minradix - '0' + 1;

    vector<int> ans;

    for (int i = max(minradix, 2); i <= 200; i++)
    {
        int a = conv(s1, i);
        int b = conv(s2, i);

        if (a >= 0 && a <= 23 && b >= 0 && b <= 59) ans.push_back(i);
    }

    if (ans.empty()) printf("0\n");
    else
    {
        int nz1 = 0, nz2 = 0;
        for (int i = 0; s1[i]; i++) if (s1[i] != '0' || nz1) nz1++;
        for (int i = 0; s2[i]; i++) if (s2[i] != '0' || nz2) nz2++;

        if (nz1 <= 1 && nz2 <= 1) printf("-1\n");
        else {
            for (int t : ans) printf("%d ", t);
            printf("\n");
        }
    }
}