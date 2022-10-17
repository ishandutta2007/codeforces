#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

bool arr[1010][1010];
int p1[1010], p2[1010], sz1[1010], sz2[1010];

_ int find1(int v) {
    return (p1[v] == v ? v : p1[v] = find1(p1[v]));
}

_ int find2(int v) {
    return (p2[v] == v ? v : p2[v] = find2(p2[v]));
}

_ bool merge1(int a, int b) {
    a = find1(a), b = find1(b);
    if (a == b) {
        return false;
    }
    if (sz1[a] < sz1[b]) {
        swap(a, b);
    }
    p1[b] = a;
    sz1[a] += sz1[b];
    return true;
}

_ bool merge2(int a, int b) {
    a = find2(a), b = find2(b);
    if (a == b) {
        return false;
    }
    if (sz2[a] < sz2[b]) {
        swap(a, b);
    }
    p2[b] = a;
    sz2[a] += sz2[b];
    return true;
}

_ void source() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a != 1 && b != 1) {
        cout << "NO";
        exit(0);
    }
    bool inv = false;
    if (a != 1) {
        inv = true;
        swap(a, b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n - b; i++) {
        arr[i][i + 1] = false;
        arr[i + 1][i] = false;
    }
    for (int i = 1; i <= n; i++) {
        p1[i] = i;
        p2[i] = i;
        sz1[i] = 1;
        sz2[i] = 1;
    }
    int kek1 = n, kek2 = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (arr[i][j] ^ inv) {
                kek1 -= merge1(i, j);
            }
            else {
                kek2 -= merge2(i, j);
            }
        }
    }
    if (inv) {
        if (kek1 != b || kek2 != a) {
            cout << "NO";
            exit(0);
        }
    }
    else {
        if (kek1 != a || kek2 != b) {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << 0;
            }
            else {
                cout << (inv ? !arr[i][j] : arr[i][j]);
            }
        }
        cout << endl;
    }
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
    source();
    return 0;
}