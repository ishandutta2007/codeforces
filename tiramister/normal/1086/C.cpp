#include <iostream>
#include <string>

using namespace std;

string a, b, ds, s, temp;
bool used[26];
bool fore, back, filled;

void fill_temp(char c, int b, int e) {
    if (temp[c - 'a'] != '$') return;
    for (int i = b; i <= e; ++i) {
        if (!used[i]) {
            temp[c - 'a'] = i + 'a';
            used[i] = true;
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        cin >> k >> ds >> a >> b;

        s = ds;
        temp = string(k, '$');
        fill(used, used + k, false);
        fore = false, back = false;

        for (int i = 0; i < a.size(); ++i) {
            if (temp[s[i] - 'a'] == '$') {
                if (fore) {
                    fill_temp(s[i], 0, b[i] - 'a');
                } else if (back) {
                    fill_temp(s[i], a[i] - 'a' + 1, k - 1);
                    fill_temp(s[i], a[i] - 'a', a[i] - 'a');
                } else {
                    fill_temp(s[i], a[i] - 'a' + 1, b[i] - 'a' - 1);
                    fill_temp(s[i], a[i] - 'a', a[i] - 'a');
                    fill_temp(s[i], b[i] - 'a', b[i] - 'a');
                }
            }

            if (temp[s[i] - 'a'] == '$') {
                s[0] = 'A';
                break;
            }
            s[i] = temp[s[i] - 'a'];

            if ((!fore && s[i] < a[i]) || (!back && b[i] < s[i])) break;
            if (a[i] < s[i]) fore = true;
            if (s[i] < b[i]) back = true;

            if (fore && back) break;
        }

        if (a <= s && s <= b) {
            cout << "YES\n";
            for (char c = 'a'; c < 'a' + k; ++c) {
                fill_temp(c, 0, k - 1);
            }

            cout << temp << "\n";
            continue;
        }

        s = ds;
        temp = string(k, '$');
        fill(used, used + k, false);
        fore = false, back = false;

        for (int i = 0; i < a.size(); ++i) {
            if (temp[s[i] - 'a'] == '$') {

                if (fore) {
                    fill_temp(s[i], 0, b[i] - 'a');
                } else if (back) {
                    fill_temp(s[i], a[i] - 'a' + 1, k - 1);
                    fill_temp(s[i], a[i] - 'a', a[i] - 'a');
                } else {
                    fill_temp(s[i], a[i] - 'a' + 1, b[i] - 'a' - 1);
                    fill_temp(s[i], b[i] - 'a', b[i] - 'a');
                    fill_temp(s[i], a[i] - 'a', a[i] - 'a');
                }
            }

            if (temp[s[i] - 'a'] == '$') {
                s[0] = 'A';
                break;
            }
            s[i] = temp[s[i] - 'a'];

            if ((!fore && s[i] < a[i]) || (!back && b[i] < s[i])) break;
            if (a[i] < s[i]) fore = true;
            if (s[i] < b[i]) back = true;

            if (fore && back) break;
        }

        if (a <= s && s <= b) {
            cout << "YES\n";
            for (char c = 'a'; c < 'a' + k; ++c) {
                fill_temp(c, 0, k - 1);
            }

            cout << temp << "\n";
            continue;
        }

        cout << "NO\n";
    }

    return 0;
}