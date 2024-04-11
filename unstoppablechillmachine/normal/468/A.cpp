#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

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
const int MAXN = 1e6 + 10;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double EPS = 1e-9;
const long double PI = acos(-1);

_ void source()
{
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "NO";
        exit(0);
    }
    cout << "YES" << endl;
    if (n % 2) {
        cout << "4 * 5 = 20\n";
        cout << "20 + 3 = 23\n";
        cout << "23 + 2 = 25\n";
        cout << "25 - 1 = 24\n";
        int operations = 4;
        for (int i = 7; i <= n; i += 2) {
            cout << i << " - " << i - 1 << " = 1\n";
            operations++;
        }
        while (operations + 1 < n) {
            cout << "24 * 1 = 24\n";
            operations++;
        }
    }
    else {
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        int operations = 3;
        for (int i = 6; i <= n; i += 2) {
            cout << i << " - " << i - 1 << " = 1\n";
            operations++;
        }
        while (operations + 1 < n) {
            cout << "24 * 1 = 24\n";
            operations++;
        }
    }
}

signed main()
{
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