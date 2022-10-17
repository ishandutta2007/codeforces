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

const int N = 1e6 + 10;
int prev[N], next[N];

_ void source() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 2; i <= n; i++) {
        if (s[i - 2] == 'r') {
            next[i] = next[i - 1];
            next[i - 1] = i;
            prev[next[i]] = i;
            prev[i] = i - 1;
        }
        else {
            next[prev[i - 1]] = i;
            next[i] = i - 1;
            prev[i] = prev[i - 1];
            prev[i - 1] = i;
        }
    }
    int a = n;
    while (prev[a]) {
        a = prev[a];
    }
    for (int i = 1; i <= n; i++) {
        cout << a << endl;
        a = next[a];
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