#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

map<vector<vector<int> >, bool> used;
queue<vector<vector<int> > > q;
int n;

vector<vector<int> > rotate1(vector<vector<int> > arr) {
    vector<vector<int> > res = arr;
    for (int i = 1; i <= n; i++) {
        res[i] = arr[n - i + 1];
    }
    return res;
}

vector<vector<int> > rotate2(vector<vector<int> > arr) {
    vector<vector<int> > res = arr;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res[i][j] = arr[i][n - j + 1];
        }
    }
    return res;
}

vector<vector<int> > turn(vector<vector<int> > arr) {
    vector<vector<int> > res = arr;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res[j][n - i + 1] = arr[i][j];
        }
    }
    return res;
}

_ void source() {
    cin >> n;
    vector<vector<int> > arr1(n + 1), arr2(n + 1);
    for (int i = 1; i <= n; i++) {
        arr1[i].rsz(n + 1);
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'X') {
                arr1[i][j] = 1;
            }
            else {
                arr1[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        arr2[i].rsz(n + 1);
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'X') {
                arr2[i][j] = 1;
            }
            else {
                arr2[i][j] = 0;
            }
        }
    }
    q.push(arr1);
    while (!q.empty()) {
        vector<vector<int> > cur = q.front();
        q.pop();
        if (cur == arr2) {
            cout << "Yes";
            exit(0);
        }
        vector<vector<int> > to1 = rotate1(cur), to2 = rotate2(cur), to3 = turn(cur);
        if (!used[to1]) {
            used[to1] = true;
            q.push(to1);
        }
        if (!used[to2]) {
            used[to2] = true;
            q.push(to2);
        }
        if (!used[to3]) {
            used[to3] = true;
            q.push(to3);
        }
    }
    cout << "No";
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
    source();
    return 0;
}