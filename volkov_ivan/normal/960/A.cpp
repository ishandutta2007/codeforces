#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt[256];
    char now_ch = 'a';
    cnt['a'] = cnt['b'] = cnt['c'] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != now_ch) {
            if (i == 0) {
                cout << "NO" << endl;
                return 0;
            }
            if (! ((s[i] == 'b' && s[i - 1] == 'a') || (s[i] == 'c' && s[i - 1] == 'b'))) {
                cout << "NO" << endl;
                return 0;
            }
        }
        now_ch = s[i];
        cnt[s[i]]++;
    }
    if (cnt['b'] == 0 || cnt['c'] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (cnt['c'] == cnt['a'] || cnt['c'] == cnt['b']) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}