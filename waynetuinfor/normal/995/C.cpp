#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1500000ll * 1500000ll;
int x[maxn], y[maxn];
int o[maxn], c[maxn];

using vec = pair<long long, long long>;

vec operator+(const vec &a, const vec &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

vec operator-(const vec &a, const vec &b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

long double abs(const vec &v) {
    return 1.0 * v.first * v.first + 1.0 * v.second * v.second;
}

vec accumulate(int n) {
    vec r = make_pair(0, 0);
    for (int i = 0; i < n; ++i) r = r + make_pair(x[i], y[i]);
    return r;
}

void upd(vec &v, vec p) {
    if (abs(p) < abs(v)) v = p;
}

void ensure(int n) {
    vec v = make_pair(0, 0);
    for (int i = 0; i < n; ++i) v = v + make_pair(c[i] * x[i], c[i] * y[i]);
    if (abs(v) > inf) assert(false);
}

int main() {
    srand(time(nullptr));
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);
    fill_n(c, n, 1);
    vec v = accumulate(n);
    for (int i = 0; i < n; ++i) o[i] = i;
    if (abs(v) > inf) {
        while (true) {
            vec p = accumulate(n);
            random_shuffle(o, o + n);
            int z = -1;
            for (int i = 0; i < n; ++i) {
                p = p - make_pair(x[o[i]], y[o[i]]);
                p = p - make_pair(x[o[i]], y[o[i]]);
                if (abs(p) <= inf) {
                    z = i;
                    break;
                }
            }
            if (z == -1) continue;
            for (int i = 0; i <= z; ++i) c[o[i]] = -1;
            break;
        }
    }
    ensure(n);
    for (int i = 0; i < n; ++i) printf("%d ", c[i]); puts("");
    return 0;
}