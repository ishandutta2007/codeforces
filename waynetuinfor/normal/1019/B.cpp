#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], query;
int n;

int ask(int i) {
    ++query;
    printf("? %d\n", i);
    fflush(stdout);
#ifdef DEBUG
    return a[i];
#else
    int x; scanf("%d", &x);
    return x;
#endif
}

void answer(int x) {
#ifdef DEBUG
    printf("query = %d\n", query);
#endif
    if (x != -1) {
        assert(a[x] == a[x + n / 2]);
    }
    printf("! %d\n", x);
    fflush(stdout);
    exit(0);
}


int main() {
    srand(time(nullptr));
    scanf("%d", &n);
#ifdef DEBUG
    a[1] = 0;
    vector<int> v;
    for (int i = 0; i < n / 2; ++i) v.push_back(1);
    for (int i = 0; i < n / 2; ++i) v.push_back(-1);
    random_shuffle(v.begin(), v.end());
    for (int i = 2; i <= n; ++i) {
        a[i] = a[i - 1] + v.back();
        v.pop_back();
    }
    assert(abs(a[1] - a[n]) == 1);
#endif
    if (n & 2) {
        answer(-1);
        return 0;
    }
    int p = 1, d = 20, px = ask(p) - ask(p + n / 2);
    if (px == 0) {
        answer(p);
        return 0;
    }
    while (d--) {
        if (p + (1 << d) <= n / 2) {
            int q = p + (1 << d), qx = ask(q) - ask(q + n / 2);
            if (qx == 0) {
                answer(q);
                return 0;
            }
            if (px > 0 && qx > 0 || px < 0 && qx < 0) p = q;
        }
    }
    answer(p);
}