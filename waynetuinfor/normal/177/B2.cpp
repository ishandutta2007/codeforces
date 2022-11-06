#include <bits/stdc++.h>
using namespace std;

const int maxn = 32000;
bool v[maxn];

int main() {
    int n; cin >> n;
    vector<int> pr;
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i);
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
    int tn = n; size_t ptr = 0;
    long long ans = n;
    while (tn > 1 && ptr < pr.size()) {
        int c = 0;
        while (tn % pr[ptr] == 0) tn /= pr[ptr], ans += tn;
        ++ptr;
    }
    if (tn > 1) ++ans;
    cout << ans << endl;
    return 0;
}