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

const int N = 110;
int prev[N], next[N];
bool used[N];
vector<int> arr[N];
_ void source() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> prev[i] >> next[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i])
            continue;
        int a = i;
        while (prev[a])
            a = prev[a];
        cnt++;
        while (a) {
            used[a] = true;
            arr[cnt].pb(a);
            a = next[a];
        }
    }
    for (int i = 1; i < cnt; i++) {
        int a = arr[i].size();
        a--;
        next[arr[i][a]] = arr[i + 1][0];
        prev[arr[i + 1][0]] = arr[i][a];
    }
    for (int i = 1; i <= n; i++) {
        cout << prev[i] << ' ' << next[i] << endl;
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