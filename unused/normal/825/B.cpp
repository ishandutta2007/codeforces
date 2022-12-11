#include <bits/stdc++.h>
using namespace std;

char dat[11][11];

bool win()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx == 0 && dy == 0) continue;

                    if (x + dx * 4 < 0 || x + dx * 4 >= 10 ||
                        y + dy * 4 < 0 || y + dy * 4 >= 10) continue;

                    bool yes = true;

                    for (int j = 0; j < 5; j++)
                    {
                        if (dat[x + dx * j][y + dy * j] != 'X') { yes = false; break; }
                    }
                    if (yes) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 10; i++) scanf("%s", dat[i]);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (dat[i][j] != '.') continue;
            dat[i][j] = 'X';
            if (win()) return !printf("YES\n");
            dat[i][j] = '.';
        }
    }

    printf("NO\n");
}