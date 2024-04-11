#include <iostream>
#include <string>
using namespace std;

int n, m, k;
string a[3000];
int ans[3000];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (a[y][x] == 'U' && y % 2 == 0) ans[x]++;
            if (a[y][x] == 'L' && x >= y) ans[x - y]++;
            if (a[y][x] == 'R' && x + y < m) ans[x + y]++;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d ", ans[i]);
    return 0;
}