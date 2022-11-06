#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
vector<int> pos[maxn];
bool v[maxn];

int main() {
    int n; cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], pos[a[i]].push_back(i), s += a[i];
    s /= (n / 2);
    for (int i = 0; i < n; ++i) if (!v[i]) {
        cout << i + 1 << ' ' << pos[s - a[i]].back() + 1 << endl;
        v[pos[s - a[i]].back()] = true;
        pos[s - a[i]].pop_back();
        v[i] = true;
    }

}