#include <iostream>
using namespace std;

int main()
{
    int empty;
    int n, m, k;
    cin >> n >> m >> k;
    k *= 4;
    while (k--) cin >> empty;
    cout << n + m - 3 + m * n << '\n';
    for (int i = 1; i < n; ++i) cout << 'U';
    for (int i = 1; i < m; ++i) cout << 'L';
    for (int i = 1; i < m; ++i) cout << 'R';
    for (int i = 1; i < n; ++i) {
        cout << 'D';
        if (i % 2) for (int j = 1; j < m; ++j) cout << 'L';
        else for (int j = 1; j < m; ++j) cout << 'R';
    }
    cout << '\n';
    return 0;
}