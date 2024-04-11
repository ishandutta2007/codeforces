#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    if (k == 1)
    {
        for (int i = 1; i <= n; i++) if (a[i] == 0) a[i] = b[1];
        if (is_sorted(a + 1, a + 1 + n)) { cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}