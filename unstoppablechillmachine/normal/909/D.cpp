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

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e6 + 10;

vector<pair<int, int> > arr;

_ void source() {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    s.ins(s.begin(), ' ');
    int cur = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[cur]) {
            arr.pb(mk(i - cur, cur));
            cur = i;
        }
    }
    arr.pb(mk(n + 1 - cur, cur));
    while (arr.size() > 1) {
        ans++;
        int a = arr.size();
        vector<bool> t(a);
        vector<pair<int, int> > arr2;
        for (int i = 0; i < a; i++) {
            if (!i || i + 1 == a) {
                arr[i].f--;
            }
            else {
                arr[i].f -= 2;
            }
            if (arr[i].f > 0) {
                arr2.pb(arr[i]);
            }
        }
        arr.clear();
        if (arr2.empty()) {
            break;
        }
        int cur = arr2[0].sec, sum = 0;
        for (auto it : arr2) {
            if (s[it.sec] == s[cur]) {
                sum += it.f;
            }
            else {
                arr.pb(mk(sum, cur));
                sum = it.f;
                cur = it.sec;
            }
        }
        arr.pb(mk(sum, cur));
    }
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