#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

long long i, i1, j, k, k1, t, n, m, res, check1, check0, a, b;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> s;
        check0 = 0; check1 = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                check0 = 1;
            } else {
                check1 = 1;
            }
        }

        if (check0 == 0 || check1 == 0) {
            cout << s << endl;
        } else {
            for (i = 0; i < s.size(); i++) {
                cout << "01";
            }
            cout << endl;
        }
    }

    return 0;
}