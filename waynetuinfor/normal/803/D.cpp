#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int k;

bool check(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> k; getline(cin, s); getline(cin, s);
    int ind = 0;
    for (int i = 0; i < s.length(); ++i) if (s[i] == ' ' || s[i] == '-') {
        vec.push_back(i - ind + 1); ind = i + 1;
    } 
    if ((int)s.length() - ind) vec.push_back((int)s.length() - ind);
    int d = 1, ans = (int)s.length(); while (d <= (int)s.length()) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}

bool check(int len) {
    int ind = 0, line = 0;
    while (ind < vec.size()) {
        int cur = vec[ind];
        if (cur > len) return false;
        while (cur <= len && ind < vec.size()) ++ind, cur += vec[ind];
        ++line; 
    }
    return line <= k;
}