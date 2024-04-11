#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < 4; ++i) {
        vector<int> c = { i };
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            vector<int> cand;
            for (int k = 0; k < 4; ++k) {
                if ((k | c.back()) == a[j - 1] &&
                    (k & c.back()) == b[j - 1]) cand.push_back(k);
            }
            if (cand.size() == 0) {
                ok = false;
                break;
            }
            assert(cand.size() == 1);
            c.push_back(cand[0]);
        }
        if (!ok) continue;
        puts("YES");
        for (int j = 0; j < n; ++j) printf("%d ", c[j]); 
        puts("");
        return 0;
    }
    puts("NO");
    return 0;
}