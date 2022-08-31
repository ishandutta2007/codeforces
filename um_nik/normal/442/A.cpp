#include <iostream>
#include <string>
using namespace std;

int n;
string s;
bool a[6][6];
int ans = 8;

void parse(string s)
{
    int x = 0;
    int y = (int)(s[1] - '1');
    if (s[0] == 'G')
        x = 1;
    else if (s[0] == 'B')
        x = 2;
    else if (s[0] == 'Y')
        x = 3;
    else if (s[0] == 'W')
        x = 4;
    a[x][y] = 1;
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        parse(s);
    }
    for (int m1 = 0; m1 < 32; m1++)
        for (int m2 = 0; m2 < 32; m2++)
        {
            int k = 0;
            for (int i = 0; i < 5; i++)
                if (m1 & (1 << i))
                    k++;
            for (int i = 0; i < 5; i++)
                if (m2 & (1 << i))
                    k++;
            if (k >= ans)
                continue;
            int x = 0;
            for (int i = 0; i < 5; i++)
                for (int j = 0; j < 5; j++)
                    if (a[i][j] && (m1 & (1 << i)) == 0 && (m2 & (1 << j)) == 0)
                        x++;
            if (x > 1)
                continue;
            bool good = 1;
            for (int i = 0; i < 5; i++)
            {
                if ((m1 & (1 << i)) == 0)
                    continue;
                int x = 0;
                for (int j = 0; j < 5; j++)
                    if (a[i][j] && (m2 & (1 << j)) == 0)
                        x++;
                if (x > 1)
                    good = 0;
            }
            for (int i = 0; i < 5; i++)
            {
                if ((m2 & (1 << i)) == 0)
                    continue;
                int x = 0;
                for (int j = 0; j < 5; j++)
                    if (a[j][i] && (m1 & (1 << j)) == 0)
                        x++;
                if (x > 1)
                    good = 0;
            }
            if (good)
                ans = min(ans, k);
        }
    printf("%d\n", ans);
    cin >> n;
    return 0;
}