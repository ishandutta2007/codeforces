#include <bits/stdc++.h>
using namespace std;

long long N, Q, i, j, k, check, ones;
string s;

int main() {
    cin >> Q;
    for (i = 0; i < Q; i++) {
        cin >> N;
        check = 0;
        ones = 0;
        for (j = 0; j < N; j++) {
            cin >> s;
            if (s.length() % 2 == 1) {
                check = 1;
            }
            for (k = 0; k < s.length(); k++) {
                if (s[k] == '1') {
                    ones++;
                }
            }
        }
        if (check == 1 || ones % 2 == 0) {
            cout << N << endl;
        } else {
            cout << N - 1 << endl;
        }
    }
    return 0;
}