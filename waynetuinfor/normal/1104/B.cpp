#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<char> v;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        v.push_back(s[i]);
        while ((int)v.size() >= 2 && v[(int)v.size() - 2] == v[(int)v.size() - 1]) {
            v.pop_back();
            v.pop_back();
            ++cnt;
        }
    }
    if (cnt & 1) puts("Yes");
    else puts("No");
    return 0;
}