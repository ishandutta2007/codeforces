#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 105;
mt19937 rng(time(0));

int T, n,m,k;

int main() {
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        cout << (k == n * m - 1 ? "YES\n" : "NO\n");
    }
    return 0;
}