#include <bits/stdc++.h>
using namespace std;

int dat[100005];
int ans[100005];
int ttt[100005];
bool yes[100005];
int tt;
int n;

int naive(int color)
{
    int res = 1;
    int now = 0;
    ++tt;
    for (int i = 0; i < n; i++)
    {
        int d = dat[i];
        if (ttt[d] != tt)
        {
            ttt[d] = tt;
            yes[d] = false;
        }

        if (yes[d] == false)
        {
            if (now == color)
            {
                ++res;
                ttt[d] = ++tt;
                now = 0;
            }
            ++now;
        }

        yes[d] = true;
    }
    return res;
}

void divide_and_conquer(int l, int r, int lo, int hi)
{
    if (l > r) return;

    int mid = (l + r) / 2;
    int res = lo == hi ? lo : naive(mid);
    ans[mid] = res;
    divide_and_conquer(l, mid - 1, res, hi);
    divide_and_conquer(mid + 1, r, lo, res);
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    
    for (int i = 1; i <= min(300, n); i++) ans[i] = naive(i);

    if (n > 300) divide_and_conquer(301, n, 1, ans[300]);

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}