#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5, M = 1e9+7;
#define runcase LOL

int chx(int X) {
    int ans = 0;
    for(; X; X /= 10) ans += X;
    return ans;
}
void solve(int test_case = 0)
{
    int L, R; cin >> L >> R;
    cout << chx(R) - chx(L) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}