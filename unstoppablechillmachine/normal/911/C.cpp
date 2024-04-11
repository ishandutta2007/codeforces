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

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long BINF = 1e18 + 10;

_ void source() {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 3);
    if (arr[0] == 1) {
        cout << "YES";
        exit(0);
    }
    if (arr[0] == 2 && (arr[1] == 2 || (arr[1] == 4 && arr[2] == 4))) {
        cout << "YES";
        exit(0);
    }
    if (arr[0] == 3 && arr[2] == 3) {
        cout << "YES";
        exit(0);
    }
    cout << "NO";
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