#include <bits/stdc++.h>
using namespace std;

int p[10005];

int main()
{
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int c = l - 1;
        for (int j = l; j <= r; j++)
        {
            if (p[j] < p[x]) ++c;
        }
        if (c == x - 1) printf("Yes\n");
        else printf("No\n");
    }
}