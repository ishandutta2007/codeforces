#include <bits/stdc++.h>

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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e6 + 10;

int fact[N];

_ int bpow(int a, int b) {
    if (!b) {
        return 1;
    }
    if (b & 1) {
        return (a * bpow(a, b - 1)) % MOD;
    }
    int k = bpow(a, b / 2);
    return (k * k) % MOD;
}

_ int inv(int a) {
    return bpow(a, MOD - 2);
}

_ void source() {
    fact[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    vector<int> d(1e6 + 10);
    for (int i = 0; i <= 1e6; i++) {
        d[i] = inv(fact[i]);
    }
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    s1.ins(s1.begin(), ' ');
    s2.ins(s2.begin(), ' ');
    vector<int> cnt(26, 0);
    for (int i = 1; i <= n; i++) {
        cnt[s1[i] - 'a']++;
    }
    int j = 1;
    while (s1[j] == s2[j]) {
        j++;
        cnt[s1[j] - 'a']--;
    }
    int pr = 1;
    for (int i = 0; i < 26; i++) {
        pr = (pr * d[cnt[i]]) % MOD;
    }
    vector<int> cnt2 = cnt;
    int prr = pr;
    int ans = 0;
    for (char ch = s1[j] + 1; ch < s2[j]; ch++) {
        if (!cnt[ch - 'a']) {
            continue;
        }
        int pr2 = (((pr * fact[cnt[ch - 'a']]) % MOD) * d[cnt[ch - 'a'] - 1]) % MOD;
        ans = (ans + fact[n - j] * pr2) % MOD;
    }
    pr = (((pr * fact[cnt[s1[j] - 'a']]) % MOD) * d[cnt[s1[j] - 'a'] - 1]) % MOD;
    cnt[s1[j] - 'a']--;
    for (int len = j + 1; len <= n; len++) {
        for (char ch = s1[len] + 1; ch <= 'z'; ch++) {
            if (!cnt[ch - 'a']) {
                continue;
            }
            int pr2 = (((pr * fact[cnt[ch - 'a']]) % MOD) * d[cnt[ch - 'a'] - 1]) % MOD;
            ans = (ans + fact[n - len] * pr2) % MOD;
        }
        pr = (((pr * fact[cnt[s1[len] - 'a']]) % MOD) * d[cnt[s1[len] - 'a'] - 1]) % MOD;
        cnt[s1[len] - 'a']--;
    }
    cnt = cnt2;
    pr = prr;
    if (cnt[s2[j] - 'a']) {
        pr = (((pr * fact[cnt[s2[j] - 'a']]) % MOD) * d[cnt[s2[j] - 'a'] - 1]) % MOD;
        cnt[s2[j] - 'a']--;
        for (int len = j + 1; len <= n; len++) {
            for (char ch = 'a'; ch < s2[len]; ch++) {
                if (!cnt[ch - 'a']) {
                    continue;
                }
                int pr2 = (((pr * fact[cnt[ch - 'a']]) % MOD) * d[cnt[ch - 'a'] - 1]) % MOD;
                ans = (ans + fact[n - len] * pr2) % MOD;
            }
            if (!cnt[s2[len] - 'a']) {
                break;
            }
            pr = (((pr * fact[cnt[s2[len] - 'a']]) % MOD) * d[cnt[s2[len] - 'a'] - 1]) % MOD;
            cnt[s2[len] - 'a']--;
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
    srand(time(0));
    source();
    return 0;
}