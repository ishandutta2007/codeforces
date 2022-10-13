#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
struct dsu {
    int n;
    vector<int> p, s;
    void init(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        s.resize(n, 1);
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int u, int v) {
        int a = find(u), b = find(v);
        if (s[a] < s[b]) swap(a, b);
        s[a] += s[b];
        p[b] = a;
    }
    int query(int free) {
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[find(i)] = s[find(i)];
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(m[i]);
        }
        sort(v.begin(), v.end());
        int ans = v.back();
        for (int j = 0; j < free; j++) {
            if (j + 2 <= n) {
                ans += v[n - j - 2];
            }
        }
        return ans;
    }
};

int main() {
    int n, d; cin >> n >> d;
    dsu curr;
    curr.init(n);
    int free = 0;
    while (d--) {
        int x, y; cin >> x >> y;
        --x, --y;
        int a = curr.find(x), b = curr.find(y);
        if (a == b) {
            ++free;
        } else {
            curr.merge(a, b);
        }
        cout << curr.query(free) - 1 << "\n";
    }
}