#include <bits/stdc++.h>
using namespace std;

char str[77];
int n;
int dp[76][76][76][3];
bool v[76][76][76][3];

char conv(char c)
{
    if (c == 'V') return 1;
    else if (c == 'K') return 2;
    else return 0;
}

int D(int l, int a, int b, int last)
{
    if (l == n + 1) return 0;

    if (v[l][a][b][last] == false)
    {
        v[l][a][b][last] = true;
        dp[l][a][b][last] = 1e9;
        int c = l - a - b - 1;

        string now;
        for (int j = 1, aa = a, bb = b, cc = c; j <= n; j++)
        {
            if (str[j] == 1)
            {
                if (bb) --bb;
                else now.push_back(str[j]);
            }
            else if (str[j] == 2)
            {
                if (cc) --cc;
                else now.push_back(str[j]);
            }
            else
            {
                if (aa) --aa;
                else now.push_back(str[j]);
            }
        }

        bool visit[3] = {};

        for (int j = 0; j < now.size(); j++)
        {
            if (visit[now[j]]) continue;
            visit[now[j]] = true;
            if (now[j] == 2 && last == 1) continue;
            dp[l][a][b][last] = min(dp[l][a][b][last],
                j + D(l + 1, a + (now[j] == 0), b + (now[j] == 1), now[j]));
        }
    }
    return dp[l][a][b][last];
}

int main()
{
    scanf("%d%s", &n, str + 1);
    for (int i = 1; i <= n; i++) str[i] = conv(str[i]);
    printf("%d\n", D(1, 0, 0, 0));
}