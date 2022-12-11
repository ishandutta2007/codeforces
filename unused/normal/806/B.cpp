#include <bits/stdc++.h>
using namespace std;

int dat[125][5];
int sum[5];
int target[5];
int ans = 1000000008;
int n;

void calc()
{
    int score1 = 0, score2 = 0;

    for (int i = 0; i < 5; i++)
    {
        if (dat[0][i] != -1) score1 += target[i] * (500 - 2 * dat[0][i]);
        if (dat[1][i] != -1) score2 += target[i] * (500 - 2 * dat[1][i]);
    }

    if (score1 <= score2) return;

    int lo = 0, hi = ans - 1;

    for (int i = 0; i < 5; i++)
    {
        if (dat[0][i] == -1)
        {
            lo = max(lo, sum[i] * (1 << (target[i] - 1)) - n);
            if (target[i] != 6) hi = min(hi, sum[i] * (1 << target[i]) - n - 1);
        }
    }

    if (lo > hi) return;

    for (; lo <= min(hi, 32); lo++)
    {
        bool wrong = false;
        for (int i = 0; i < 5; i++)
        {
            if (dat[0][i] == -1) continue;
            int lower = (target[i] == 6 ? 0 : 1 << target[i]);
            int upper = 1 << (target[i] - 1);

            int L = (lower == 0) ? 0 : (n + lo) / lower + 1;
            int R = (n + lo) / upper;
            if (L > R)
            {
                wrong = true; break;
            }

            if (sum[i] > R || sum[i] + lo < L)
            {
                wrong = true; break;
            }
        }

        if (wrong == false)
        {
            ans = min(ans, lo);
            return;
        }
    }

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        
        bool wrong = false;
        for (int i = 0; i < 5; i++)
        {
            if (dat[0][i] == -1) continue;
            int lower = (target[i] == 6 ? 0 : 1 << target[i]);
            int upper = 1 << (target[i] - 1);

            int L = (lower == 0) ? 0 : (n + mid) / lower + 1;
            int R = (n + mid) / upper;
            if (L > R)
            {
                wrong = true; break;
            }

            if (sum[i] > R || sum[i] + mid < L)
            {
                wrong = true; break;
            }
        }

        if (wrong == false)
        {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &dat[i][j]);
            if (dat[i][j] != -1) sum[j]++;
        }
    }

#define F(a) for(target[a] = 1; target[a] <= 6; target[a]++)
    F(0) F(1) F(2) F(3) F(4) calc();

    if (ans == 1000000008) ans = -1;

    printf("%d\n", ans);
}