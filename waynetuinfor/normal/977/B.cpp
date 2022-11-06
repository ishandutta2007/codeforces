#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s; cin >> n >> s;
    map<string, int> cc;
    for (int i = 0; i < n - 1; ++i) cc[s.substr(i, 2)]++;
    string ans = "";
    int z = -1;
    for (auto i : cc) {
        if (i.second > z) z = i.second, ans = i.first;
    }
    cout << ans << endl;
}