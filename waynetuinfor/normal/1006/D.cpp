#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
char a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", a), scanf("%s", b);
    int ans = 0;
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) ++ans;
    for (int i = 0; i < n / 2; ++i) {
        char ax = a[i], ay = a[n - 1 - i];
        char bx = b[i], by = b[n - 1 - i];
        vector<char> v = { ax, ay, bx, by };
        sort(v.begin(), v.end());
        vector<int> t;
        for (int i = 0; i < v.size(); ) {
            int j = i;
            while (j < v.size() && v[j] == v[i]) ++j;
            t.push_back(j - i);
            i = j;
        }
        sort(t.begin(), t.end());
        if (t.size() == 1) continue;
        if (t.size() == 2 && t[0] == 2 && t[1] == 2) continue;
        if (t.size() == 2 && t[0] == 1 && t[1] == 3) ++ans;
        else if (t.size() == 4) ans += 2;
        else if (t.size() == 3) {
            if (ax == ay) ans += 2;
            else if (ax == bx || ax == by || ay == bx || ay == by) ++ans;
            else if (bx == by) ++ans;
        }
    }
    printf("%d\n", ans);
}