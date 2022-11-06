#include <bits/stdc++.h>
using namespace std;

vector<int> tva, tvb;

bool check(int t, int a, int b) {
    set<int> s;
    for (int i = 1; i <= t; ++i) s.insert(i);
    vector<int> va, vb;
    while (a > 0 && s.size()) {
        if (*s.begin() > a) break;
        auto it = s.upper_bound(a);
        if (it != s.begin()) {
            int x = *prev(it);
            a -= x;
            va.push_back(x);
            s.erase(x);
        }
    } 
    long long sum = 0;
    for (int x : s) vb.push_back(x), sum += x;
    if (sum <= b) {
        tva = va;
        tvb = vb;
        return true;
    }
    return false;
}

int main() {
    int a, b; scanf("%d%d", &a, &b);
    int d = 20, ans = 0;
    while (d--) {
        if (ans + (1 << d) > 100000) continue;
        if (check(ans + (1 << d), a, b)) ans += (1 << d);
    }
    printf("%d\n", tva.size());
    for (int i : tva) printf("%d ", i); puts("");
    printf("%d\n", tvb.size());
    for (int i : tvb) printf("%d ", i); puts("");
}