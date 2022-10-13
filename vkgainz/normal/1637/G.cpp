#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <numeric>

using namespace std;

vector<pair<int, int>> ans;
int ge[100001];
int lg[100001];

void comb(int x, int y, int shift) {
    ans.push_back({x << shift, y << shift});
}

void put(int x, int y) {
    ans.push_back({x, y});
    ans.push_back({abs(x - y), x + y});
}

void sim(vector<pair<int, int>> &in, int n) {
    multiset<int> curr;
    for (int i = 1; i <= n; i++) {
        curr.insert(i);
    }
    for (auto &it : in) {
        int x = it.first, y = it.second;
        if (!curr.count(x) || !curr.count(y)) {
            cout << "BRUH" << "\n";
            return;
        }
        curr.erase(curr.lower_bound(x));
        curr.erase(curr.lower_bound(y));
        curr.insert(abs(x - y));
        curr.insert(x + y);
    }
    for (auto &it : curr) cout << it << " ";
    cout << "\n";
}

vector<int> solve(int n, int shift) {
    if (n == 0) { return vector<int>(shift + 1); }
    if (ge[n] == n) {
        vector<int> a = solve(n - 1, shift);
        while (a.size() <= lg[ge[n]] + shift) a.push_back(0);
        ++a[lg[ge[n]] + shift];
        return a;
    }
    int spl = ge[n] / 2;
    vector<int> ans(shift + lg[ge[n]] + 1);
    ++ans[lg[spl] + shift];
    for (int j = spl + 1; j <= n; j++) {
        comb(j, 2 * spl - j, shift);
        ++ans[lg[ge[n]] + shift];
    }
    vector<int> r = solve(2 * spl - n - 1, shift);
    vector<int> s = solve(n - spl, shift + 1);
    for (int i = 0; i <= shift + lg[ge[n]]; i++) {
        if (i < r.size()) ans[i] += r[i];
        if (i < s.size()) ans[i] += s[i];
    }
    return ans;
}

int main() {
    int t; cin >> t;
    ge[1] = 1;
    lg[1] = 0;
    for (int i = 2; i <= 100000; i++) {
        if (i > ge[i - 1]) {
            ge[i] = ge[i - 1] * 2;
            lg[i] = lg[i - 1] + 1;
        } else {
            ge[i] = ge[i - 1];
            lg[i] = lg[i - 1];
        }
    }
    while (t--) {
        int n; cin >> n;
        ans.clear();
        if (n == 2) cout << -1 << "\n";
        else {
            vector<int> left = solve(n, 0);
            int numZero = 0;
            for (int i = 0; i < left.size() - 1; i++) {
                for (int j = 0; j < left.size() - 1; j++) {
                    if (left[j] >= 2) {
                        comb(1, 1, j);
                        ++left[j + 1];
                        left[j] -= 2;
                        ++numZero;
                        --j;
                    }
                }
                if (left[i] == 0) continue;
                if (left[i] == 1) {
                    if (numZero == 0) {
                        put(1 << i, 1 << (i + 1));
                        ++left[i + 1];
                        ++left[i + 2];
                        --left[i];
                        --left[i + 1];
                    } else {
                        comb(0, 1, i);
                        ++left[i];
                        --numZero;
                        --i;
                    }
                } else if (left[i] >= 2) {
                    comb(1, 1, i);
                    ++left[i + 1];
                    left[i] -= 2;
                    ++numZero;
                    --i;
                }
            }
            for (int i = 0; i < numZero; i++) {
                comb(0, 1, left.size() - 1);
                ++left.back();
            }
            //sim(ans, n);
            cout << ans.size() << "\n";
            for (auto &it : ans) {
                cout << it.first << " " << it.second << "\n";
            }
        }
    }
}