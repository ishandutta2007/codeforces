#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int>> ans;

void put(string &s, int pos, char x) {
    if (s[pos] == x) return;
    int pos2 = pos + 1;
    while (pos2 < (int) s.length() && s[pos2] != x) pos2++;
    if (pos2 == (int) s.length()) exit(-1);
    ans.push_back({pos, pos2});
    reverse(s.begin() + pos, s.begin() + pos2 + 1);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t = "";
    for (int i = 0; i < k - 1; i++) {
        t += "()";
    }
    int rest = (n - (2 * (k - 1))) / 2;
    for (int i = 0; i < rest; i++) t += "(";
    for (int i = 0; i < rest; i++) t += ")";
    ans.clear();
    for (int i = 0; i < n; i++) put(s, i, t[i]);
    cout << ans.size() << endl;
    for (auto elem : ans) {
        cout << elem.first + 1 << ' ' << elem.second + 1 << endl;
    }
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}