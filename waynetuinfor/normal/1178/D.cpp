#include <bits/stdc++.h>
using namespace std;

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

const int maxn = 1000 + 5;
int deg[maxn], c[maxn];

int main() {
    int n; scanf("%d", &n);
    if (n == 4) {
        cout << 5 << endl;
        cout << 1 << ' ' << 2 << endl;
        cout << 1 << ' ' << 3 << endl;
        cout << 2 << ' ' << 3 << endl;
        cout << 2 << ' ' << 4 << endl;
        cout << 3 << ' ' << 4 << endl;
        return 0;
    }
    int m = n;
    while (!prime(m)) ++m;

    vector<pair<int, int>> edge;

    int s = 0, sz = 0;

    if (n % 3 == 1) {
        edge.emplace_back(0, 1);
        edge.emplace_back(1, 2);
        edge.emplace_back(2, 3);
        edge.emplace_back(3, 0);
        deg[0] = deg[1] = deg[2] = deg[3] = 2;
        c[0] = c[1] = c[2] = c[3] = 0;
        sz = 1;
        s = 4;
    } else if (n % 3 == 2) {
        edge.emplace_back(0, 1);
        edge.emplace_back(1, 2);
        edge.emplace_back(2, 3);
        edge.emplace_back(3, 4);
        edge.emplace_back(4, 0);
        deg[0] = deg[1] = deg[2] = deg[3] = deg[4] = 2;
        c[0] = c[1] = c[2] = c[3] = c[4] = 0;
        sz = 1;
        s = 5;
    }

    assert((n - s) % 3 == 0);

    for (int i = s; i < n; i += 3) {
        edge.emplace_back(i, i + 1);
        edge.emplace_back(i, i + 2);
        edge.emplace_back(i + 1, i + 2);
        deg[i] = deg[i + 1] = deg[i + 2];
        c[i] = c[i + 1] = c[i + 2] = sz++;
    }

    set<int> all;
    for (int i = 0; i < n; ++i) all.insert(i);

    while ((int)edge.size() < m) {
        int x = *all.begin(); all.erase(all.begin());
        int f = -1;
        for (int it : all) {
            if (c[it] != c[x]) {
                deg[x]++;
                deg[it]++;
                edge.emplace_back(x, it);
                f = it;
                break;
            }
        }
        if (f != -1) all.erase(f);
    }
    assert(prime(edge.size()));
    for (int i = 0; i < n; ++i) assert(prime(deg[i]));

    printf("%d\n", (int)edge.size());
    for (auto e : edge) printf("%d %d\n", e.first + 1, e.second + 1);
    return 0;
}