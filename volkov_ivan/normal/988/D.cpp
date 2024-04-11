#include <iostream>
#include <set>

using namespace std;

const long long MAX_N = 2e9 + 7;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long a[n];
    set <long long> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    bool two = 0;
    pair <long long, long long> ans_two;
    for (int i = 0; i < n; i++) {
        long long d = 1;
        while (d < MAX_N) {
            if (s.find(a[i] - d) != s.end()) {
                two = 1;
                ans_two = make_pair(a[i] - d, a[i]);
                if (s.find(a[i] + d) != s.end()) {
                    cout << 3 << endl << a[i] - d << ' ' << a[i] << ' ' << a[i] + d << endl;
                    return 0;
                }
            } else if (s.find(a[i] + d) != s.end()) {
                two = 1;
                ans_two = make_pair(a[i], a[i] + d);
            }
            d *= 2;
        }
    }
    if (two) cout << 2 << endl << ans_two.first << ' ' << ans_two.second << endl;
    else cout << 1 << endl << a[0] << endl;
    return 0;
}