#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; long long s;
    scanf("%d %d %lld", &n, &k, &s);
    int pos = 1;
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
        int to = abs(pos - 1) > abs(pos - n) ? 1 : n;
        int dt = abs(pos - to);
        if (dt <= s && (k - 1 - i) <= s - dt) {
            s -= dt;
            ans.push_back(to);
            pos = to;
            continue;
        } 
        dt = s - (k - 1 - i);
        if (dt <= 0) {
            puts("NO");
            return 0;
        }
        bool ok = false;
        if (pos - dt >= 1) {
            ans.push_back(pos - dt);
            s -= dt;
            pos -= dt;
            ok = true;
        } else if (pos + dt <= n) {
            ans.push_back(pos + dt);
            s -= dt;
            pos += dt;
            ok = true;
        }
        if (!ok) {
            puts("NO");
            return 0;
        }
    }
    if (s > 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
    puts("");
    return 0;
}