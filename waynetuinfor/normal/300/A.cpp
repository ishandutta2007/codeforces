#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int main() {
    int n; cin >> n;
    deque<int> b, c, d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) d.push_back(a[i]);
        else if (a[i] > 0) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    if (b.size() == 0) b.push_back(c[0]), b.push_back(c[1]), c.pop_front(), c.pop_front();
    if (c.size() % 2 == 0) d.push_back(c[0]), c.pop_front();
    cout << c.size() << ' ';
    for (int i : c) cout << i << ' '; cout << endl;
    cout << b.size() << ' ';
    for (int i : b) cout << i << ' '; cout << endl;
    cout << d.size() << ' ';
    for (int i : d) cout << i << ' '; cout << endl;
    return 0;
}