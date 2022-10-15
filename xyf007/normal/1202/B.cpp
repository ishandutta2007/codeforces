#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string s;
int ans[10][10][10][10];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
void init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    int sum = 2e9;
                    for (int m = 0; m < 20; m++)
                    {
                        for (int n = 0; n < 20; n++)
                        {
                            if (!m && !n)
                            {
                                continue;
                            }
                            if (m + n - 1>= sum)
                            {
                                break;
                            }
                            if ((i + k * m + l * n) % 10 == j)
                            {
                                checkmin(sum, m + n - 1);
                            }
                        }
                    }
                    if (sum == 2e9)
                    {
                        ans[i][j][k][l] = -1;
                    }
                    else
                    {
                        ans[i][j][k][l] = sum;
                    }
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> s;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int anss = 0;
            bool f = 0;
            for (int k = 0; k < (int)s.size() - 1; k++)
            {
                int l = s[k] - '0', r = s[k + 1] - '0';
                if (ans[l][r][i][j] == -1)
                {
                    cout << "-1" << ' ';
                    f = 1;
                    break;
                }
                else
                {
                    anss += ans[l][r][i][j];
                }
            }
            if (!f)
            {
                cout << anss << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}