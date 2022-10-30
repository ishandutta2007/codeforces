#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#define LL long long
#define pii pair <int, int>

using namespace std;

const int N = 100100;

int mp[1100][1100];

int main () {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        scanf ("%d%d", &x, &y);
        mp[x][y] = 1;
        if (mp[x - 1][y] && mp[x][y - 1] && mp[x - 1][y - 1] ||
            mp[x + 1][y] && mp[x][y - 1] && mp[x + 1][y - 1] ||
            mp[x - 1][y] && mp[x][y + 1] && mp[x - 1][y + 1] ||
            mp[x + 1][y] && mp[x][y + 1] && mp[x + 1][y + 1]) {
            printf ("%d", i);
            return 0;
        }
    }
    printf ("0");
}