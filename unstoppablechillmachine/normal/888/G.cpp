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

const int root = 1;
const int N = 1e7 + 10;

int mp1[N], mp2[N], cnt;

void add(int a, int cur) {
    int v = root;
    for (int i = cur; i >= 0; i--) {
        int b = ((a & (1 << i)) ? 1 : 0);
        if (b) {
            if (!mp1[v]) {
                cnt++;
                mp1[v] = cnt;
            }
            v = mp1[v];
        }
        else {
            if (!mp2[v]) {
                cnt++;
                mp2[v] = cnt;
            }
            v = mp2[v];
        }
    }
}

int go(int a, int cur) {
    int res = 0, v = root;
    for (int i = cur; i >= 0; i--) {
        int b = ((a & (1 << i)) ? 1 : 0);
        if (b) {
            if (!mp1[v]) {
                res += (1 << i);
                assert(mp2[v]);
                v = mp2[v];
            }
            else {
                v = mp1[v];
            }
        }
        else {
            if (!mp2[v]) {
                res += (1 << i);
                assert(mp1[v]);
                v = mp1[v];
            }
            else {
                v = mp2[v];
            }
        }
    }
    return res;
}

_ int get(vector<int> &arr, int bit) {
    if (bit < 0) {
        return 0;
    }
    if (arr.empty()) {
        return 0;
    }
    vector<int> arr1, arr2;
    for (auto &it : arr) {
        if (it & (1 << bit)) {
            arr1.pb(it);
        }
        else {
            arr2.pb(it);
        }
    }
    int res = get(arr1, bit - 1) + get(arr2, bit - 1);
    if (arr1.empty() || arr2.empty()) {
        return res;
    }
    int mn = INF;
    for (int i = 1; i <= cnt; i++) {
        mp1[i] = 0;
        mp2[i] = 0;
    }
    cnt = 1;
    for (auto &it : arr2) {
        add(it, bit);
    }
    for (auto &it : arr1) {
        mn = min(mn, go(it, bit));
    }
    return res + mn;
}

_ void source() {
    int n;
    vector<int> arr;
    cin >> n;
    arr.rsz(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << get(arr, 30);
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