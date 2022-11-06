#include <bits/stdc++.h>
using namespace std;

int cnt[1000];
int main() {
    int _; cin >>_;
    string s; cin >> s;
    int n = s.length();
    for (int i = 0; i < s.length(); ++i) ++cnt[s[i]];
    if (cnt['I'] == 1) return cout << "1" << endl, 0;
    if (cnt['A'] + cnt['F'] == n) return cout << cnt['A'] << endl, 0;
    cout << 0 <<endl;
}