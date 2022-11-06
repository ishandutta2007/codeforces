#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int o = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') ++o;
    } 
    int z = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            ++z;
            continue;
        }
        if (s[i] == '2') {
            for (int j = 0; j < z; ++j) cout << 0;
            for (int j = 0; j < o; ++j) cout << 1;
            for (int j = i; j < s.size(); ++j) if (s[j] != '1') cout << s[j];
            cout << endl;
            return 0;
        }
    }
    for (int i = 0; i < s.size() - o; ++i) cout << 0;
    for (int i = 0; i < o; ++i) cout << 1;
    cout << endl;
    return 0;
}