#include <bits/stdc++.h>
using namespace std;

long long N, i, j, k, o[300000], e[300000], oi, ei, oi1, ei1;
string s, res[300000];

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> s;
        oi = 0;
        ei = 0;
        for (j = 0; j < s.length(); j++) {
            if (s[j] == '0' || s[j] == '2' || s[j] == '4' || s[j] == '6' || s[j] == '8') {
                e[ei] = s[j];
                ei++;
            } else {
                o[oi] = s[j];
                oi++;
            }
        }
        oi1 = 0;
        ei1 = 0;
        for (j = 0; j < s.length(); j++) {
            if (oi1 < oi && ei1 < ei) {
                if (e[ei1] < o[oi1]) {
                    res[j] = e[ei1];
                    ei1++;
                } else {
                    res[j] = o[oi1];
                    oi1++;
                }
            } else {
                if (oi1 < oi) {
                    res[j] = o[oi1];
                    oi1++;
                } else {
                    res[j] = e[ei1];
                    ei1++;
                }
            }
        }
        for (j = 0; j < s.length(); j++) {
            cout << res[j];
        }
        if (i != N - 1) {
            cout << endl;
        }
    }
    return 0;
}