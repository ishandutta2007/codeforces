#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, k;
char s[N], ans[N];
int cnt[150];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> (s + 1);
        n = strlen(s + 1);
        rep(i, 'a', 'z') cnt[i] = 0;
        rep(i, 1, n) cnt[s[i]]++;
        int mi = n;
        rep(i, 'a', 'z') if (cnt[i]) mi = min(mi, cnt[i]);

        if (mi == n)
            rep(i, 1, n) ans[i] = s[i];
        else if (mi == 1) { // f = 0
            rep(i, 'a', 'z') if (cnt[i] == 1) {
                ans[1] = i;
                cnt[i]--;
                break;
            }
            int m = 1;
            rep(i, 'a', 'z') rep(j, 1, cnt[i]) ans[++m] = i;
        } else { // f = 1
            char first;
            rep(i, 'a', 'z') if (cnt[i]) {
                first = i;
                break;
            }
            if (cnt[first] * 2 <= n + 2) { // start with two
                ans[1] = ans[2] = first;
                cnt[first] -= 2;
                int j = first + 1, num = 2;
                rep(i, 1, cnt[first]) {
                    while (j <= 'z' && cnt[j] == 0)
                        j++;
                    cnt[j]--, ans[++num] = j, ans[++num] = first;
                }
                while (j <= 'z') {
                    while (j <= 'z' && cnt[j] == 0)
                        j++;
                    if (cnt[j])
                        cnt[j]--, ans[++num] = j;
                }
            } else { // start with one
                int diff_ch = 0;
                rep(i, 'a', 'z') if (cnt[i]) diff_ch++;
                if (diff_ch == 2) {
                    ans[1] = first, cnt[first]--;
                    int j = first + 1, num = 1;
                    while (j <= 'z' && cnt[j] == 0)
                        j++;
                    rep(i, 1, cnt[j]) ans[++num] = j;
                    rep(i, 1, cnt[first]) ans[++num] = first;
                } else {
                    ans[1] = first, cnt[first]--;
                    int num = 1, j = first + 1, k;
                    while (j <= 'z' && cnt[j] == 0)
                        j++;
                    k = j + 1;
                    while (k <= 'z' && cnt[k] == 0)
                        k++;
                    ans[++num] = j, cnt[j]--;
                    rep(i, 1, cnt[first]) ans[++num] = first;
                    cnt[first] = 0;
                    ans[++num] = k, cnt[k]--;
                    rep(i, 'a', 'z') if (cnt[i]) rep(j, 1, cnt[i]) ans[++num] = i;
                }
            }
        }
        ans[n + 1] = 0;
        cout << (ans + 1) << endl;
    }
    return 0;
}