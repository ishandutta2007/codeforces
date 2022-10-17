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

string s;
pair<int, int> from, to;
bool arr[100][100];
map<char, char> mp;
int n, m;

_ bool check() {
    pair<int, int> now = from;
    for (int i = 0; i < s.size(); i++) {
        if (mp[s[i]] == 'U') {
            now.f--;
            if (!now.f || arr[now.f][now.sec]) {
                return false;
            }
            if (now == to) {
                return true;
            }
        }
        else if (mp[s[i]] == 'D') {
            now.f++;
            if (now.f > n || arr[now.f][now.sec]) {
                return false;
            }
            if (now == to) {
                return true;
            }
        }
        else if (mp[s[i]] == 'L') {
            now.sec--;
            if (!now.sec || arr[now.f][now.sec]) {
                return false;
            }
            if (now == to) {
                return true;
            }
        }
        else {
            now.sec++;
            if (now.sec > m || arr[now.f][now.sec]) {
                return false;
            }
            if (now == to) {
                return true;
            }
        }
    }
    return false;
}

_ void source() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                arr[i][j] = 1;
            }
            if (ch == 'S') {
                from = mk(i, j);
            }
            if (ch == 'E') {
                to = mk(i, j);
            }
        }
    }
    cin >> s;
    vector<char> ar;
    int ans = 0;
    ar.pb('U');
    ar.pb('D');
    ar.pb('L');
    ar.pb('R');
    sort(all(ar));
    do {
        for (int i = 0; i < 4; i++) {
            mp[char('0' + i)] = ar[i];
        }
        if (check()) {
            ans++;
        }
    } while (next_permutation(all(ar)));
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