#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 5e15 + 5;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n;
int a[N], b[N], cnt[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) cin >> b[i];
        int j = 1;
        rep(i, 1, n) {
            if (a[i] == b[j]) {
                while (j <= n && a[i] == b[j] && cnt[b[j]])
                    cnt[b[j]]--, j++;
                if (a[i] == b[j])
                    j++;
                else
                    cnt[a[i]]++;
            } else {
                cnt[a[i]]++;
            }
        }
        cout << (j > n ? "YES\n" : "NO\n");

        rep(i, 1, n) cnt[a[i]] = 0;
    }
    return 0;
}