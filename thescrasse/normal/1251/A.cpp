#include <bits/stdc++.h>
using namespace std;

long long N, i, j, k;
string s;
char c, i1;
map<char, int> res;

int main() {
    cin >> N;
    for (i = 0; i < N; i++) {
        res.clear();
        cin >> s;
        c = s[0];
        s[s.length()] = '1';
        k = 1;
        for (j = 1; j <= s.length(); j++) {
            if (s[j] == c) {
                k++;
            } else {
                if (k % 2 == 1) {
                    res[c] = 1;
                }
                c = s[j];
                k = 1;
            }
        }
        for (i1 = 'a'; i1 <= 'z'; i1++) {
            if (res[i1] == 1) {
                cout << i1;
            }
        }
        cout << endl;
    }
    return 0;
}