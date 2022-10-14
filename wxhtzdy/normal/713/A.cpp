#include <bits/stdc++.h>

using namespace std;

int get(long long x) {
    int res = 0;
    for (int i = 0; i < 20; i++) {
        res = 2 * res + (x & 1);
        x /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    map<int, int> cnt;
    while (tt--) {
        char foo;
        cin >> foo;
        long long s;
        cin >> s;
        if (foo == '+') {
            cnt[get(s)]++;
        } else {
            if (foo == '-') {
                cnt[get(s)]--;
            } else {
                cout << cnt[get(s)] << '\n';
            }
        }
    }
    return 0;
}