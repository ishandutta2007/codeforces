#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;
int t, n, k, a[200001];
bool cmp(int x, int y)
{
    return x > y;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1, cmp);
        cout <<  accumulate(a + 1, a + k + 2, 0LL) << '\n';
    }
    return 0;
}