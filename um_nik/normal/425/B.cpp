#include <iostream>
#include <set>
using namespace std;

int n, m, k, ans = 100;
int a[200][200];
int b[200][200];
set< pair<int, int> > c;
int sz = 0;

void move2(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    a[x][y] ^= 1;
    if (a[x][y] == 0)
    {
        c.erase( c.find( make_pair(x, y) ) );
    }
    else
    {
        c.insert( make_pair(x, y) );
    }
    return;
}

void move(int x, int y)
{
    move2(x, y);
    move2(x + 1, y);
    move2(x, y + 1);
    move2(x + 1, y + 1);
    return;
}

void solve()
{
    if (c.empty())
    {
        ans = min(ans, sz);
        return;
    }
    sz++;
    if (sz > k)
    {
        sz--;
        return;
    }
    int x = (*c.begin()).first;
    int y = (*c.begin()).second;
    x--;
    y--;
    move(x, y);
    solve();
    move(x, y);
    x++;
    move(x, y);
    solve();
    move(x, y);
    x--;
    y++;
    move(x, y);
    solve();
    move(x, y);
    x++;
    move(x, y);
    solve();
    move(x, y);
    sz--;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    n--;
    m--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = (b[i][j] + b[i][j + 1] + b[i + 1][j] + b[i + 1][j + 1]) % 2;
    if (n * m == 0)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 1)
                c.insert( make_pair(i, j) );

    if ((int)c.size() > 40)
    {
        printf("-1\n");
        return 0;
    }

    solve();

    if (ans > k)
        printf("-1\n");
    else
        printf("%d\n", ans);

//  cin >> n;
    return 0;
}