#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
char s[10], ans[maxn];
int n;

bool ask(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return false;
    assert(r1 >= 1 && r1 <= n);
    assert(c1 >= 1 && c1 <= n);
    assert(r2 >= 1 && r2 <= n);
    assert(c2 >= 1 && c2 <= n);
    assert(r2 - r1 + c2 - c1 >= n - 1);
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    scanf("%s", s);
    return s[0] == 'Y';
}

bool valid(int r1, int c1, int r2, int c2) {
    return r1 <= r2 && c1 <= c2;
}

int main() {
    scanf("%d", &n);
    int a = 1, b = 1, x = n, y = n;
    vector<pair<int, int>> p = { make_pair(a, b) };
    for (int i = 0; i < n - 1; ++i) {
        if (a + 1 <= n && ask(a + 1, b, n, n)) ++a;
        else if (b + 1 <= n && ask(a, b + 1, n, n)) ++b;
        p.emplace_back(a, b);
    }
    vector<pair<int, int>> q = { make_pair(x, y) };
    int j = p.size() - 2;
    int z = p.back().first, w = p.back().second;
    for (int i = 0; i < n - 1; ++i) {
        int c, d; tie(c, d) = p[j]; --j;
        if (y - 1 >= 1 && valid(z, w, x, y - 1) && ask(c, d, x, y - 1)) --y;
        else if (x - 1 >= 1 && valid(z, w, x - 1, y) && ask(c, d, x - 1, y)) --x;
        q.emplace_back(x, y);
    }
    // assert(p.back() == q.back());
    j = 0;
    for (int i = 1; i < p.size(); ++i) {
        if (p[i].first > p[i - 1].first) ans[j++] = 'D';
        else ans[j++] = 'R';
    }
    for (int i = q.size() - 1; i >= 1; --i) {
        if (q[i - 1].first > q[i].first) ans[j++] = 'D';
        else ans[j++] = 'R';
    }
    assert(j == 2 * n - 2);
    printf("! ");
    for (int i = 0; i < j; ++i) printf("%c", ans[i]);
    printf("\n");
    fflush(stdout);
}