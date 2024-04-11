#include <bits/stdc++.h>

/*#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")*/

using namespace std;

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void source() {
    string s1, s2;
    cin >> s1 >> s2;
    string ans;
    if (s1.size() < s2.size()) {
        sort(rall(s1));
        cout << s1;
        exit(0);
    }
    int n = s1.size();
    vector<int> cnt(10);
    for (int i = 0; i < n; i++) {
        cnt[s1[i] - '0']++;
    }
    string cur;
    for (int i = 0; i < n; i++) {
        int j = s2[i] - '0';
        j--;
        while (j >= 0 && !cnt[j]) {
            j--;
        }
        if (j >= 0) {
            if (i || j) {
                string cur2 = cur;
                char ch = '0' + j;
                cur2 += ch;
                cnt[j]--;
                for (int k = 9; k >= 0; k--) {
                    for (int p = 0; p < cnt[k]; p++) {
                        char ch = '0' + k;
                        cur2 += ch;
                    }
                }
                ans = max(ans, cur2);
                cnt[j]++;
            }
        }
        j = s2[i] - '0';
        if (!cnt[j]) {
            break;
        }
        cur += s2[i];
        cnt[j]--;
        if (i + 1 == n) {
            ans = max(ans, cur);
        }
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}