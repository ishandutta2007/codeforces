#include <stdio.h>
#include <algorithm>

char ch[3][200005];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < 3; i++) scanf("%s",ch[i]);

        int p[3] = {};

        for (int i = 0; i < 3 * n; i++)
        {
            bool fin = false;
            for (int a = 0; a < 3 && !fin; a++)
            {
                for (int b = a + 1; b < 3; b++)
                {
                    if (ch[a][p[a]] == ch[b][p[b]])
                    {
                        putchar(ch[a][p[a]] & 1 ? '1' : '0');
                        if (p[a] < 2 * n) ++p[a];
                        if (p[b] < 2 * n) ++p[b];
                        fin = true;
                        break;
                    }
                }
            }

            if (!fin)
            {
                int maxi = -1;
                for (int a = 0; a < 3; a++)
                {
                    if (p[a] == 2 * n) continue;
                    if (maxi == -1 || p[a] > p[maxi]) maxi = a;
                }
                putchar(maxi == -1 ? '0' : ch[maxi][p[maxi]++]);
            }
        }
        putchar('\n');
    }
}