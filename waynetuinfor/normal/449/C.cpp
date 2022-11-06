#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int size[maxn];
bool v[maxn];
vector<int> p;

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) p.push_back(i);
        for (int j = 0; i * p[j] < maxn; ++j) {
            v[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int n; cin >> n;
    set<int> s;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) s.insert(i);
    sort(p.begin(), p.end(), [&](const int& a, const int& b) { return n / a < n / b; });
    for (int i : p) {
        vector<int> f;
        for (int j = 1; i * j <= n; ++j) {
            if (s.count(i * j)) f.push_back(i * j);
        }
        if (f.size() & 1) {
            for (int j = 0; j < f.size(); j += 2) {
                if (j + 1 >= f.size()) continue;
                if (f[j] == 2 * i) {
                    if (j + 2 >= f.size()) continue;
                    ans.push_back(make_pair(f[j + 1], f[j + 2]));
                    s.erase(f[j + 1]); s.erase(f[j + 2]);
                } else if (f[j + 1] == 2 * i) {
                    if (j + 2 >= f.size()) continue;
                    ans.push_back(make_pair(f[j], f[j + 2]));
                    s.erase(f[j]); s.erase(f[j + 2]);
                    ++j;
                } else {
                    ans.push_back(make_pair(f[j], f[j + 1]));
                    s.erase(f[j]); s.erase(f[j + 1]);
                }
            }
        } else {
            for (int j = 0; j < f.size(); j += 2) {
                ans.push_back(make_pair(f[j], f[j + 1]));
                s.erase(f[j]); s.erase(f[j + 1]);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first << ' ' << i.second << endl;
    return 0;
}