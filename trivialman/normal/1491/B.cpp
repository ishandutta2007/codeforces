#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 105, M = 1005;
mt19937 rng(time(0));

int T,n, u, v;
int a[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> u >> v;
        rep(i, 1, n) cin >> a[i];
        bool flag = false;
        rep(i, 2, n) if (abs(a[i] - a[i - 1]) >= 2) flag = true;
        if (flag) {
            cout << "0\n";
        } else {
            rep(i, 2, n) 
                if (a[i] != a[i - 1])
                    flag = true;
            cout << (flag ? min(u, v) : v + min(u, v)) << endl;
        }
    }
    return 0;
}