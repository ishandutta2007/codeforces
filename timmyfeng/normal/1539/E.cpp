#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int last_l[N], last_r[N], ans[N];

void trim(map<int, int> &s, int l, int r) {
    while (!s.empty() && s.begin()->first < l) {
        s.erase(s.begin());
    }

    while (!s.empty() && (--s.end())->first > r) {
        s.erase(--s.end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int last = 0;
    map<int, int> left = {{0, 0}}, right = {{0, 0}};
    for (int i = 1; i <= n; ++i) {
        int k, al, bl, ar, br;
        cin >> k >> al >> bl >> ar >> br;

        bool empty_r = right.empty(), empty_l = left.empty();

        if (!empty_r && ar <= last && last <= br) {
            left[last] = i - 1;
        }

        if (!empty_l && al <= last && last <= bl) {
            right[last] = i - 1;
        }

        if (al <= k && k <= bl) {
            trim(left, ar, br);
        } else {
            left.clear();
        }
        last_r[i] = left.empty() ? -1 : left.begin()->second;

        if (ar <= k && k <= br) {
            trim(right, al, bl);
        } else {
            right.clear();
        }
        last_l[i] = right.empty() ? -1 : right.begin()->second;

        last = k;
    }

    int dir;
    if (!left.empty()) {
        dir = 0;
    } else if (!right.empty()) {
        dir = 1;
    } else {
        cout << "No\n";
        exit(0);
    }

    int i = n;
    while (i > 0) {
        int j = (dir == 0 ? last_r : last_l)[i];
        for (int k = j + 1; k <= i; ++k) {
            ans[k] = dir;
        }
        dir = 1 - dir, i = j;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}