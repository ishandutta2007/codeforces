#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, p;
        string s;
        cin >> a >> b >> p >> s;
        s.pop_back();
        while (!s.empty()) {
            char tmp = s.back();
            if (tmp == 'A') {
                if (a <= p) {
                    p -= a;
                } else break;
            } else {
                if (b <= p) {
                    p -= b;
                } else break;
            }
            while (s.back() == tmp) {
                s.pop_back();
            }
        }
        cout << s.size() + 1 << '\n';
    }
}