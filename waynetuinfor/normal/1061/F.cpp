#include <bits/stdc++.h>
using namespace std;

char res[100];

bool query(int x, int y, int z) {
    // does y lies on the path from x to z
    printf("? %d %d %d\n", x + 1, y + 1, z + 1);
    fflush(stdout);
    scanf("%s", res);
    return res[0] == 'Y';
}

int main() {
    srand(clock() + time(nullptr));
    int n, k; scanf("%d%d", &n, &k);
    int height = -1, sum = 0, cur = 1;
    while (sum < n) {
        sum += cur;
        cur *= k;
        height++;
    }
    int x = -1, y = -1;
    while (true) {
        int c = rand() % n, d = rand() % n;
        while (c == d) c = rand() % n, d = rand() % n;
        bool leaf = true;
        for (int i = 0; i < n; ++i) {
            if (i == c || i == d) continue;
            bool q = query(i, c, d);
            if (q) {
                leaf = false;
                break;
            }
        }
        if (leaf) {
            x = c;
            break;
        }
    }
    vector<int> up;
    while (true) {
        y = rand() % n;
        while (x == y) y = rand() % n;
        int dist = 0;
        vector<int> buf;
        for (int i = 0; i < n; ++i) {
            if (i == x || i == y) continue;
            if (query(x, i, y)) ++dist, buf.push_back(i);
        }
        if (dist == 2 * height - 1) {
            up = buf;
            break;
        }
    }
    for (int i = 0; i < (int)up.size(); ++i) {
        int dist = 0;
        for (int j = 0; j < n; ++j) {
            if (j == x || j == up[i]) continue;
            if (query(x, j, up[i])) ++dist;
        }
        if (dist == height - 1) {
            printf("! %d\n", up[i] + 1);
            fflush(stdout);
            return 0;
        }
    }
    assert(false);
}