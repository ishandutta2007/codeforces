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

const int N = 210;

map<char, bool> t;
bool used[N][N][N];
void dfs(int a, int b, int c) {
    used[a][b][c] = true;
    if (a + b + c == 1) {
        if (a == 1) {
            t['B'] = true;
        }
        else if (b == 1) {
            t['G'] = true;
        }
        else {
            t['R'] = true;
        }
        return;
    }
    if (a > 1 && !used[a - 1][b][c]) {
        dfs(a - 1, b, c);
    }
    if (b > 1 && !used[a][b - 1][c]) {
        dfs(a, b - 1, c);
    }
    if (c > 1 && !used[a][b][c - 1]) {
        dfs(a, b, c - 1);
    }
    if (a && b && !used[a - 1][b - 1][c + 1]) {
        dfs(a - 1, b - 1, c + 1);
    }
    if (a && c && !used[a - 1][b + 1][c - 1]) {
        dfs(a - 1, b + 1, c - 1);
    }
    if (c && b && !used[a + 1][b - 1][c - 1]) {
        dfs(a + 1, b - 1, c - 1);
    }
}

_ void source() {
    int n;
    map<char, int> cnt;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        cnt[ch]++;
    }
    dfs(cnt['B'], cnt['G'], cnt['R']);
    if (t['B']) {
        cout << 'B';
    }
    if (t['G']) {
        cout << 'G';
    }
    if (t['R']) {
        cout << 'R';
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