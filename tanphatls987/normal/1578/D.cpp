#include <bits/stdc++.h>

using namespace std;



typedef long long ll;
typedef pair<ll, ll> ii;

#define X first
#define Y second

const ll INF = 1e18 + 10;
const double EPS = 1e-8;

template <class T>
bool minimize(T &x, T y) {
    if (y < x) x = y;
    else return 0;
    return 1;
}

const int N = 1e6 + 10;

int n;
double p;

void prepare() {
    cin >> n >> p;
}

long long C(int n, int m) {
    if (m > n || m < 0) return 0;
    long long ans = 1;
    for(int i = 0; i < m; i++) {
        ans *= n - i;
    }
    for(int i = 0; i < m; i++) {
        ans /= (i + 1);
    }
    return ans;
}
bool check(int m) {
    long long mp = 0;
    long long cp3 = C(m, 3) * C(n - m, 0);
    //cout << cp3 << endl;
    /// overlap 3 card
    mp += 2 * cp3;
    //cout << mp << endl;



    long long cp2 = C(m, 2) * C(n - m, 1);
    //cout << cp2 << endl;
    /// overlap 2 card
    mp += 2 * cp2;
    //cout << mp << endl;

    long long cp1 = C(m, 1) * C(n - m, 2);
    //cout << cp1 << endl;
    /// overlap 1 card

    mp += cp1;
    //cout << m << " " << mp << endl;
    return mp >= 2 * p * C(n, 3) - EPS;
}
void solve() {
    int L = 0, R = n;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) R = mid - 1;
        else L = mid + 1;
    }
    cout << L;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    prepare();
    solve();
}