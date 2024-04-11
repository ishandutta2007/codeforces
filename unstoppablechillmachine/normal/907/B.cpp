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

char arr[10][10];

int get(int a) {
    return a / 3 + (a % 3 != 0);
}

int get2(int a) {
    if (!a) {
        return 3;
    }
    return a % 3;
}

_ void source() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> arr[i][j];
        }
    }
    int x, y;
    bool t = false;
    cin >> x >> y;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (get(i) % 3 == get2(x) && get(j) % 3 == get2(y) && arr[i][j] == '.') {
                arr[i][j] = '!';
                t = true;
            }
        }
    }
    if (!t) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (arr[i][j] == '.') {
                    arr[i][j] = '!';
                }
            }
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << arr[i][j];
            if (j % 3 == 0) {
                cout << ' ';
            }
        }
        cout << endl;
        if (i % 3 == 0) {
            cout << endl;
        }
    }
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