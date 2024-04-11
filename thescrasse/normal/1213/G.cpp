// 1213G
// percorsi su un tree con massimo peso di un arco <= q[i]
// idee: sorto i q[i], aggiungo nuovi archi con la dsu

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a, b, c, u, v, w, s1, s2, q[200010], link[200010], size[200010], f[200020];
vector<pair<long long, pair<long long, long long>>> el;

int find(int s) {
    while (link[s] != s) {
        s = link[s];
    }
    return s;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] > size[b]) {
        swap(a, b);
    }
    link[a] = b;
    size[b] += size[a];
}

long long binom(long long a) {
    return (a * (a - 1)) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        el.push_back({w, {u, v}});
    }

    for (i = 1; i <= n; i++) {
        link[i] = i;
        size[i] = 1;
    }

    if (n != 1) {
        sort(el.begin(), el.end());
    }
    k = 0;
    f[0] = 0;
    for (i = 1; i <= 200010; i++) {
        if (k >= n - 1) {
            for (j = i; j <= 200010; j++) {
                f[j] = f[i - 1];
            }
            break;
        }
        f[i] = f[i - 1];
        while (el[k].first == i) {
            a = el[k].second.first;
            b = el[k].second.second;
            s1 = size[find(a)];
            s2 = size[find(b)];
            // cout << s1 << ' ' << s2 << endl;
            f[i] = f[i] + binom(s1 + s2) - binom(s1) - binom(s2);
            unite(a, b);
            k++;
            if (k >= n - 1) {
                for (j = i + 1; j <= 200010; j++) {
                    f[j] = f[i];
                }
                break;
            }
        }
    }

    for (i = 0; i < m; i++) {
        cin >> a;
        cout << f[a] << ' ';
    }

    return 0;
}