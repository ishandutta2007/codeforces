#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m, a[2001], b[2001], c[2001], d[2001];
vector<int> v(1000005);
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] > c[j])
            {
                continue;
            }
            checkmax(v[c[j] - a[i]], d[j] - b[i] + 1);
        }
    }
    int ans = 1e7, maxx = 0;
    for (int i = 1000001; i >= 0; i--)
    {
        checkmax(maxx, v[i]);
        checkmin(ans, maxx + i);
    }
    cout << ans;
    return 0;
}