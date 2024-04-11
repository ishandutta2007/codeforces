#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = (1 << 30) - 1;
const int N = 1e4+5;
mt19937 rng(time(0));

int T, n, k, a[N];

int ask(int i, int j){
    int x, y;
    cout << "and " << i << " " << j << endl;
    cin >> x;
    cout << "or " << i << " " << j << endl;
    cin >> y;
    return x + y;
}

int main() {
    cin >> n >> k;
    int x = ask(1, 2), y = ask(1, 3), z = ask(2, 3);
    a[1] = (x + y - z) / 2, a[2] = (x + z - y) / 2, a[3] = (y + z - x) / 2;
    rep(i, 4, n) a[i] = ask(1, i) - a[1];
    sort(a + 1, a + n + 1);
    cout << "finish " << a[k] << endl;
    return 0;
}