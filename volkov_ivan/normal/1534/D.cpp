#include <bits/stdc++.h>
//#define int long long

using namespace std;

int n;
set <pair <int, int>> ee;

vector <int> ask(int v) {
    cout << "? " << v << endl;
    vector <int> res(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> res[i];
    return res;
}

void relax(int v, int u) {
    if (v > u)
        swap(v, u);
    ee.insert({v, u});
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    auto d = ask(1);
    vector <int> ch, nech;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 1)
            relax(1, i);
        if (d[i] % 2 == 1)
            nech.push_back(i);
        else
            ch.push_back(i);
    }
    auto vv = ch;
    if (nech.size() < ch.size())
        vv = nech;
    for (auto elem : vv) {
        d = ask(elem);
        for (int i = 1; i <= n; i++) {
            if (d[i] == 1)
                relax(elem, i);
        }
    }
    cout << "!" << endl;
    for (auto elem : ee) {
        cout << elem.first << ' ' << elem.second << endl;
    }
    assert((int) ee.size() == n - 1);
    return 0;
}