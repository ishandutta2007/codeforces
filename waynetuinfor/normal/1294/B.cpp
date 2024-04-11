#include <bits/stdc++.h>
using namespace std;

const int kN = 1000;
int x[kN], y[kN];
bool v[kN];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
        for (int i = 0; i < n; ++i) v[i] = false;
        int ds = 0;
        for (int i = 0; i < n; ++i) ds = max(ds, x[i] + y[i]);
        int a = 0, b = 0;
        string ans = "";
        for (int i = 0; i < ds; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (!v[j] && (x[j] < a + 1 || y[j] < b)) ok = false;
            }
            if (ok) ans += 'R', a++;
            else ans += 'U', b++;
            for (int j = 0; j < n; ++j) {
                if (x[j] == a && y[j] == b) v[j] = true;
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) ok &= v[i];
        if (!ok) puts("NO");
        else printf("YES\n%s\n", ans.c_str());
    }
    return 0;
}