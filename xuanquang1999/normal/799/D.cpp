#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int a, b, w, h, n;
vector<int> c;
vector<pair<int, int> > scale;

int expand(int dimension, int base, int exponent) {
    int res = dimension;
    for(int i = 0; i < exponent; ++i)
        res = min(1LL*MAXN, 1LL*res*base);
    return res;
}

bool tryExpand(int i, int w, int h) {
    if (w >= a && h >= b)
        return true;
    if (i == scale.size())
        return false;

    for(int j = 0; j <= scale[i].second; ++j) {
        int newW = expand(w, scale[i].first, j);
        int newH = expand(h, scale[i].first, scale[i].second-j);
        if (tryExpand(i+1, newW, newH))
            return true;
    }
}

bool check(int k) {
    vector<int> cnt(MAXN);
    for(int i = 0; i < k; ++i)
        ++cnt[c[i]];

    scale.clear();
    for(int x = 0; x < MAXN; ++x)
        if (cnt[x])
            scale.push_back({x, cnt[x]});

    return (tryExpand(0, w, h) || tryExpand(0, h, w));
}

int main() {
    scanf("%d%d%d%d%d", &a, &b, &w, &h, &n);
    c.resize(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &c[i]);

    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    for(int i = 0; i <= n; ++i) {
        if (check(i)) {
            printf("%d\n", i);
            return 0;
        }
    }

    puts("-1");

    return 0;
}