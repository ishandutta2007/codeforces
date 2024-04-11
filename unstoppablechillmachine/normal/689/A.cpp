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

_ void source() {
    vector<pair<int, int> > arr(10);
    arr[0] = mk(4, 2);
    arr[1] = mk(1, 1);
    arr[2] = mk(1, 2);
    arr[3] = mk(1, 3);
    arr[4] = mk(2, 1);
    arr[5] = mk(2, 2);
    arr[6] = mk(2, 3);
    arr[7] = mk(3, 1);
    arr[8] = mk(3, 2);
    arr[9] = mk(3, 3);
    set<pair<int, int> > st;
    for (int i = 0; i < 10; i++) {
        st.ins(arr[i]);
    }
    int n;
    cin >> n;
    vector<int> now;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        now.pb(ch - '0');
    }
    for (int first = 0; first < 10; first++) {
        if (first == now[0]) {
            continue;
        }
        bool t = true;
        pair<int, int> delta = mk(arr[first].f - arr[now[0]].f, arr[first].sec - arr[now[0]].sec);
        for (int i = 1; i < now.size(); i++) {
            pair<int, int> p = mk(arr[now[i]].f + delta.f, arr[now[i]].sec + delta.sec);
            if (st.find(p) == st.end()) {
                t = false;
            }
        }
        if (t) {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
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