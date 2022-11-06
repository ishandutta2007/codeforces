#include <bits/stdc++.h>
using namespace std;

const int kN = 15;
const int kInf = 1e9 + 100;
vector<int> a[kN];
bool dp[1 << kN], gd[1 << kN];
vector<pair<int, int>> cy[1 << kN];
uint32_t p[1 << kN];
int to[kN], w[kN];
int64_t s[kN];

int main() {
    int k; scanf("%d", &k);
    map<int, int> rev;
    int64_t sum = 0;
    for (int i = 0; i < k; ++i) {
        int n; scanf("%d", &n);
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            rev[a[i][j]] = i;
            sum += a[i][j];
            s[i] += a[i][j];
        }
    }
    if (sum % k != 0) {
        puts("No");
        return 0;
    }
    int64_t target = sum / k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            int v = i, w = a[i][j];
            uint32_t mask = (1 << i);
            bool fl = false;
            vector<pair<int, int>> f;
            while (true) {
                int64_t need = target - (s[v] - w); 
                if (abs(need) > kInf || rev.find(need) == rev.end()) {
                    fl = true;
                    break;
                }
                f.emplace_back(v, w);
                int z = rev[need];
                if (z == i) {
                    if (need != a[i][j]) fl = true;
                    break;
                }
                if (mask >> z & 1) {
                    fl = true;
                    break;
                }
                mask |= (1 << z);
                w = need;
                v = z;
            }
            if (!fl) {
                gd[mask] = true;
                cy[mask] = f;
            }
        }
    }
    for (uint32_t s = 0; s < (1U << k); ++s) {
        if (gd[s]) {
            dp[s] = true;
            continue;
        }
        uint32_t sub = s;
        while (sub) {
            sub = (sub - 1) & s;
            if (dp[sub] && dp[s ^ sub]) {
                dp[s] = true;
                p[s] = sub;
                break;
            }
        }
    }
    if (!dp[(1U << k) - 1]) {
        puts("No");
        return 0;
    }
    queue<uint32_t> q;
    q.push((1U << k) - 1);
    while (!q.empty()) {
        uint32_t s = q.front();
        q.pop();
        if (gd[s]) {
            int pv = cy[s].back().first;
            for (int i = 0; i < cy[s].size(); ++i) {
                to[cy[s][i].first] = pv;
                w[cy[s][i].first] = cy[s][i].second;
                pv = cy[s][i].first;
            }
        } else {
            assert(dp[s]);
            q.push(p[s]);
            q.push(p[s] ^ s);
        }
    }
    puts("Yes");
    for (int i = 0; i < k; ++i) printf("%d %d\n", w[i], to[i] + 1);
    return 0;
}