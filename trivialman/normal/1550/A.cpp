#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 5005;

int T, n, x;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cout << (int)(sqrt(n - 1) + 1) << endl;
    }
    return 0;
}