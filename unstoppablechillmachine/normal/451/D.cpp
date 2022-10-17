#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

const int N = 1e6 + 10;
int pref[N], suf_odd[N][2], suf_even[N][2], sum[2];

pair<int, int> solve(string s) {
    int ans_odd = 0, ans_even = 0, cnta_odd = 0, cnta_even = 0, cntb_odd = 0, cntb_even = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            if (i % 2) {
                cnta_odd++;
                ans_even += cnta_even;
                ans_odd += cnta_odd;
            }
            else {
                cnta_even++;
                ans_even += cnta_odd;
                ans_odd += cnta_even;
            }
        }
        else {
            if (i % 2) {
                cntb_odd++;
                ans_even += cntb_even;
                ans_odd += cntb_odd;
            }
            else {
                cntb_even++;
                ans_even += cntb_odd;
                ans_odd += cntb_even;
            }
        }
    }
    return {ans_even, ans_odd};
}

_ void source() {
    string s;
    cin >> s;
    /*vector<int> arr;
    char prev = s[0], len = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != prev) {
            arr.pb(len);
            prev = s[i];
            len = 1;
        }
        else {
            len++;
        }
    }
    arr.pb(len);
    int n = arr.size();
    arr.ins(arr.begin(), 0);
    for (int i = 1; i <= n; i++) {
        int cnt_odd = arr[i] / 2 + arr[i] % 2, cnt_even = arr[i] - cnt_odd;
        sum[1] += cnt_odd * (cnt_odd + 1) / 2;
        sum[1] += cnt_even * (cnt_even + 1) / 2;
        sum[0] += cnt_even * cnt_odd;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }
    for (int i = n; i >= 1; i--) {
        int c = pref[i - 1] % 2;
        suf_odd[i][c] = suf_odd[i + 2][c] + arr[i] / 2 + arr[i] % 2;
        suf_even[i][c] = suf_even[i + 2][c] + arr[i] / 2;
        suf_odd[i][c ^ 1] = suf_odd[i + 2][c ^ 1];
        suf_even[i][c ^ 1] = suf_even[i + 2][c ^ 1];
    }
    for (int l = 1; l <= n; l++) {
        int cnt_odd = arr[l] / 2 + arr[l] % 2, cnt_even = arr[l] - cnt_odd;
        int c = pref[l] % 2;
        sum[0] += cnt_odd * suf_odd[l + 2][c] + cnt_even * suf_even[l + 2][c] + cnt_odd * suf_even[l + 2][c ^ 1] + cnt_even * suf_odd[l + 2][c ^ 1];
        sum[1] += cnt_odd * suf_odd[l + 2][c ^ 1] + cnt_even * suf_even[l + 2][c ^ 1] + cnt_odd * suf_even[l + 2][c] + cnt_even * suf_odd[l + 2][c];
    }
    pair<int, int> ans = solve(s);
    assert(sum[0] == ans.f && sum[1] == ans.sec);
    cout << sum[0] << ' ' << sum[1];*/
    pair<int, int> ans = solve(s);
    cout << ans.f << ' ' << ans.sec;
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