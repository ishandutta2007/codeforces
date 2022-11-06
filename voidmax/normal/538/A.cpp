#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <vector>
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

string s;


main() {
    //freopen("input.txt", "r", stdin);
    //freopen("", "r", stdin);freopen("", "w", stdout);
    cin >> s;
    if (s.size() >= 9) {
        For(i, 0, 11) {
            string ans = "";
            For(q, 0, i) {
                ans += s[q];
            }
            For(q, (int)s.size() + i - 10, s.size()) {
                ans += s[q];
            }
            if (ans == "CODEFORCES") {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}