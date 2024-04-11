#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool isCorrect(string s) {
    int cur = 0;
    for(char c: s) {
        cur += (c == '(') ? 1 : -1;
        if (cur < 0)
            return false;
    }

    return (cur == 0);
}

int main() {
    cin >> n >> s;

    for(int i = n-1; i >= 0; --i) {
        if (s[i] == '(') {
            s.erase(s.begin() + i);
            s = "(" + s;
            break;
        }
    }

    cout << (isCorrect(s) ? "Yes" : "No");

    return 0;
}