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
//#define int ll
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
const long double PI = acos(-1);

_ void source() {
    int n, k;
    string s1, s2;
    cin >> n >> k;
    cin >> s1 >> s2;
    int cnt1 = n, cnt2 = n;
    string s3;
    s3 = s1;
    for (int i = 0; i < n; i++) {
        s3[i] = 'a';
        while (s3[i] == s1[i] || s3[i] == s2[i]) {
            s3[i]++;
        }
    }
    if (k == n) {
        cout << s3;
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            s3[i] = s1[i];
            cnt1--;
            cnt2--;
        }
        if (cnt1 == k) {
            cout << s3;
            exit(0);
        }
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (cnt1 > cnt2) {
                s3[i] = s1[i];
                cnt1--;
            }
            else {
                s3[i] = s2[i];
                cnt2--;
            }
        }
        if (cnt1 == k && cnt2 == k) {
            cout << s3;
            exit(0);
        }
    }
    cout << -1;
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