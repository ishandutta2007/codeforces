#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n, k;
char s[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d\n", &n, &k);
        scanf("%s\n", s + 1);
        bool flag = true;
        rep(i, 1, k) {
            int j;
            bool flag0 = false, flag1 = false;
            for (j = i; j <= n; j += k) {
                if (s[j] == '0')
                    flag0 = true;
                if (s[j] == '1')
                    flag1 = true;
            }
            if (flag0 && flag1)
                flag = false;
            for (j = i; j <= n; j += k)
                if (flag0)
                    s[j] = '0';
                else if (flag1)
                    s[j] = '1';
        }

        rep(i, 1, n) if (s[i] != '?' && i - k >= 1 && s[i] != s[i - k]) flag = false;
        int cnt0 = 0, cnt1 = 0;
        rep(i, 1, k) {
            cnt0 += (s[i] == '0');
            cnt1 += (s[i] == '1');
        }
        if (cnt0 > k / 2 || cnt1 > k / 2)
            flag = false;
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}