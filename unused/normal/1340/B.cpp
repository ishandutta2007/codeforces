#include <bits/stdc++.h>
using namespace std;

const char* digitdata[] =
{
     "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int digits[10];
int dat[2005];
int dp[2005][2005];
int n;

int D(int x, int y)
{
    if (x == n)
    {
        return y == 0 ? 0 : -2;
    }

    if (dp[x][y] == -1)
    {
        dp[x][y] = -2;
        for (int i = 9; i >= 0; i--)
        {
            // digits[i] should include all dat[i]
            if ((dat[x] & digits[i]) != dat[x]) continue;
            int change = __builtin_popcount(dat[x] ^ digits[i]);
            if (change > y) continue;
            if (D(x + 1, y - change) >= 0)
            {
                dp[x][y] = i;
                break;
            }
        }
    }

    return dp[x][y];
}

void recur(int x, int y)
{
    if (x == n)
    {
        printf("\n");
        return;
    }

    int res = D(x, y);
    printf("%d", res);
    recur(x + 1, y - __builtin_popcount(dat[x] ^ digits[res]));
}

int main()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 10; i++)
    {
        digits[i] = bitset<8>(digitdata[i]).to_ulong();
    }
    int k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        char s[10];
        scanf("%s", s);
        dat[i] = bitset<8>(s).to_ulong();
    }

    if (D(0, k) < 0)
    {
        printf("-1\n");
    }
    else
    {
        recur(0, k);
    }
}