#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    string s;
    cin >> s;
    int n = s.length();
    vector <int> res;
    int l = 0, r = n - 1;
    while (l < r) {
        while (l < n && s[l] == ')') l++;
        while (r >= 0 && s[r] == '(') r--;
        if (l >= r) break;
        res.push_back(l + 1);
        res.push_back(r + 1);
        l++;
        r--;
    }
    if (res.empty()) {
        cout << "0" << endl;
        return 0;
    }
    cout << 1 << endl;
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (int elem : res) cout << elem << ' ';
    return 0;
}