#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
int P = 998244353;
const int INF = 1e9 + 1;
const int N = 1005;
mt19937 rng(time(0));

int T, n;
int a[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << (a[n - 1] + a[n]) << "\n";
    }
    return 0;
}