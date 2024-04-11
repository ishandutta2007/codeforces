//I_l_M_P
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

struct event {
    int f, sec, num;
};

int len(int a, int b) {
    return a * a + b * b;
}

bool cmp(event a, event b) {
    return len(a.f, a.sec) > len(b.f, b.sec);
}

_ void source() {
    int n;
    cin >> n;
    vector<event> arr(n);
    vector<int> ans(n);
    int num = 0;
    for (auto &it : arr) {
        cin >> it.f >> it.sec;
        it.num = num;
        num++;
    }
    sort(all(arr), cmp);
    int cur_x = 0, cur_y = 0, lim = int(1e12 * 2.25);
    for (int i = 0; i < n; i++) {
        int tox1 = cur_x + arr[i].f, tox2 = cur_x - arr[i].f, toy1 = cur_y + arr[i].sec, toy2 = cur_y - arr[i].sec;
        if (len(tox1, toy1) < len(tox2, toy2)) {
            ans[arr[i].num] = 1;
            cur_x = tox1;
            cur_y = toy1;
        }
        else {
            ans[arr[i].num] = -1;
            cur_x = tox2;
            cur_y = toy2;
        }
    }
    if (len(cur_x, cur_y) <= lim) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        exit(0);
    }
    reverse(all(arr));
    cur_x = 0;
    cur_y = 0;
    for (int i = 0; i < n; i++) {
        int tox1 = cur_x + arr[i].f, tox2 = cur_x - arr[i].f, toy1 = cur_y + arr[i].sec, toy2 = cur_y - arr[i].sec;
        if (len(tox1, toy1) < len(tox2, toy2)) {
            ans[arr[i].num] = 1;
            cur_x = tox1;
            cur_y = toy1;
        }
        else {
            ans[arr[i].num] = -1;
            cur_x = tox2;
            cur_y = toy2;
        }
    }
    if (len(cur_x, cur_y) <= lim) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        exit(0);
    }
    while (true) {
        shuffle(all(arr), Random);
        cur_x = 0;
        cur_y = 0;
        for (int i = 0; i < n; i++) {
            int tox1 = cur_x + arr[i].f, tox2 = cur_x - arr[i].f, toy1 = cur_y + arr[i].sec, toy2 = cur_y - arr[i].sec;
            if (len(tox1, toy1) < len(tox2, toy2)) {
                ans[arr[i].num] = 1;
                cur_x = tox1;
                cur_y = toy1;
            }
            else {
                ans[arr[i].num] = -1;
                cur_x = tox2;
                cur_y = toy2;
            }
        }
        if (len(cur_x, cur_y) <= lim) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << ' ';
            }
            exit(0);
        }
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
    source();
    return 0;
}