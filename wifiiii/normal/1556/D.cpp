#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    auto And = [&](int x, int y) {
        cout << "and " << x + 1 << " " << y + 1 << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    auto Or = [&](int x, int y) {
        cout << "or " << x + 1 << " " << y + 1 << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    vector<int> a(n), b(n);
    for(int i = 1; i < n; ++i) {
        int x = And(0, i), y = Or(0, i);
        b[i] = x + y; // a[0] + a[i]
    }
    int tmp = And(1, 2) + Or(1, 2); // a[1] + a[2]
    a[1] = ((b[1] - b[2]) + tmp) / 2;
    a[0] = b[1] - a[1];
    for(int i = 2; i < n; ++i) a[i] = b[i] - a[0];
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {return a[x] < a[y];});
    cout << "finish " << a[ord[k-1]] << endl;
}