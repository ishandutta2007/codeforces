#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, a1, c1, h2, a2; cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector<string> v;
    while (h2 > 0) {
        if (h2 - a1 <= 0) {
            v.push_back("STRIKE");
            break;
        }
        if (h1 - a2 <= 0) v.push_back("HEAL"), h1 += c1;
        else v.push_back("STRIKE"), h2 -= a1;
        h1 -= a2;
    }
    cout << v.size() << endl;
    for (auto i : v) cout << i << endl;
    return 0;
}