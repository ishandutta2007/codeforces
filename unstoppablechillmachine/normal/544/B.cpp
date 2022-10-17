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
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int n = 110;
int arr[110][110];

_ void source() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= n; j += 2) {
                if (cnt == k) {
                    break;
                }
                arr[i][j] = 1;
                cnt++;
            }
        }
        else {
            for (int j = 2; j <= n; j += 2) {
                if (cnt == k) {
                    break;
                }
                arr[i][j] = 1;
                cnt++;
            }
        }
    }
    if (cnt < k) {
        cout << "NO";
        exit(0);
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (arr[i][j] ? 'L' : 'S');
        }
        cout << endl;
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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