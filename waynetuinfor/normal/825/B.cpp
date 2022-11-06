#include <bits/stdc++.h>
using namespace std;

string s[10];

bool win(const string s[10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) if (s[i][j] == 'X') {
            int cnt = 0;
            for (int k = 0; k < 5 && j + k < 10; ++k) if (s[i][j + k] == 'X') ++cnt;
            if (cnt == 5) return true;
            cnt = 0;
            for (int k = 0; k < 5 && j - k >= 0; ++k) if (s[i][j - k] == 'X') ++cnt;
            if (cnt == 5) return true;
            cnt = 0;
            for (int k = 0; k < 5 && i + k < 10; ++k) if (s[i + k][j] == 'X') ++cnt;
            if (cnt == 5) return true;
            cnt = 0;
            for (int k = 0; k < 5 && i - k >= 0; ++k) if (s[i - k][j] == 'X') ++cnt;
            if (cnt == 5) return true;
            cnt = 0;
            for (int k = 0; k < 5 && i + k < 10 && j + k < 10; ++k) if (s[i + k][j + k] == 'X') ++cnt;
            if (cnt == 5) return true;
            cnt = 0;
            for (int k = 0; k < 5 && i + k < 10 && j - k >= 0; ++k) if (s[i + k][j - k] == 'X') ++cnt;
            if (cnt == 5) return true;
            cnt = 0;
            for (int k = 0; k < 5 && i - k >= 0 && j + k < 10; ++k) if (s[i - k][j + k] == 'X') ++cnt;
            if (cnt == 5) return true;
            cnt = 0;
            for (int k = 0; k < 5 && i - k >= 0 && j - k >= 0; ++k) if (s[i - k][j - k] == 'X') ++cnt;
            if (cnt == 5) return true;
        }
    }
    return false;
}
int main() {
    for (int i = 0; i < 10; ++i) cin >> s[i];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (s[i][j] == '.') {
                s[i][j] = 'X';
                if (win(s)) return cout << "YES" << endl, 0;
                s[i][j] = '.';
            }
        }
    }
    cout << "NO" << endl; return 0;
}