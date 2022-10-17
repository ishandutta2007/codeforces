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

const int N = 5010;

int n, m, mx;
string s[N];
int pref[N][N];
_ bool check(int cnt) {
    return (cnt == 2 || (cnt == 0 && mx > 1));
}

_ void source() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i].ins(s[i].begin(), ' ');
    }
    vector<int> arr(26);
    for (int i = 1; i <= m; i++) {
        arr[s[1][i] - 'a']++;
        mx = max(mx, arr[s[1][i] - 'a']);
    }
    for (int i = 2; i <= n; i++) {
        vector<int> arr2(26);
        for (int j = 1; j <= m; j++) {
            arr2[s[i][j] - 'a']++;
        }
        if (arr2 != arr) {
            cout << -1;
            exit(0);
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j - 1] + (s[i][j] != s[1][j]);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (pref[i][m] > 4) {
            cout << -1;
            exit(0);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            string ss = s[1];
            swap(ss[i], ss[j]);
            bool t = true;
            for (int k = 2; k <= n; k++) {
                int cnt = 0;
                cnt += ss[i] != s[k][i];
                cnt += ss[j] != s[k][j];
                cnt += pref[k][m] - (s[1][i] != s[k][i]) - (s[1][j] != s[k][j]);
                if (!check(cnt)) {
                    t = false;
                    break;
                }
            }
            if (t) {
                ss.ers(ss.begin());
                cout << ss;
                exit(0);
            }
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