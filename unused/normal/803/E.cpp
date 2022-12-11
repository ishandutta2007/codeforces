#include <bits/stdc++.h>
using namespace std;

int n, k;

bool dp[1005][2005];
bool v[1005][2005];
char dat[1005];

bool D(int idx, int diff)
{
    if (idx == n) return diff == 0 || diff == 2 * k;
    if (diff == 0 || diff == 2 * k) return false;

    if (v[idx][diff] == false)
    {
        v[idx][diff] = true;

        if (dat[idx] == 'W' || dat[idx] == '?') dp[idx][diff] |= D(idx + 1, diff + 1);
        if (dat[idx] == 'D' || dat[idx] == '?') dp[idx][diff] |= D(idx + 1, diff);
        if (dat[idx] == 'L' || dat[idx] == '?') dp[idx][diff] |= D(idx + 1, diff - 1);
    }

    return dp[idx][diff];
}

void recur(int idx, int diff)
{
    if (idx == n) return;

    if (dat[idx] == 'W' || (dat[idx] == '?' && D(idx + 1, diff + 1))) printf("W"), recur(idx + 1, diff + 1);
    else if (dat[idx] == 'D' || (dat[idx] == '?' && D(idx + 1, diff))) printf("D"), recur(idx + 1, diff);
    else printf("L"), recur(idx + 1, diff - 1);
}

int main()
{
    scanf("%d%d%s", &n, &k, dat);
    if (D(0, k) == false) printf("NO\n");
    else
    {
        recur(0, k);
        printf("\n");
    }
}