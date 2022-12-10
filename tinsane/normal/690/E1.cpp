#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 605;
const int THRESHOLD = 10;

int n, m;
int pic[N][N];

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &pic[i][j]);

    int h1 = n / 2 - 1;
    int h2 = n / 2;

    int cnt = 0;
    for (int i = 0; i < m; i++)
        if (abs(pic[h1][i] - pic[h2][i]) > THRESHOLD)
            cnt++;

    puts(cnt >= m / 2 ? "YES" : "NO");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}