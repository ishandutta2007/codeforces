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
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 5e5 + 10;

int p[N], rk[N];
vector<int> kk[N];
vector<pair<int, int> > change_color[N], change_rk[N];
void make1(int v) {
    p[v] = v;
    rk[v] = 1;
    kk[v].pb(v);
    change_color[v].pb(mk(0, v));
    change_rk[v].pb(mk(0, 1));
    return;
}

int get1(int v) {
    return (p[v] == v ? v : get1(p[v]));
}

void merge1(int a, int b, int cur_cost) {
    a = get1(a);
    b = get1(b);
    if (a == b) {
        return;
    }
    if (rk[a] < rk[b]) {
        swap(a, b);
    }
    p[b] = a;
    rk[a] += rk[b];
    rk[b] = 0;
    change_rk[a].pb(mk(cur_cost, rk[a]));
    change_rk[b].pb(mk(cur_cost, rk[b]));
    for (auto it : kk[b]) {
        kk[a].pb(it);
        change_color[it].pb(mk(cur_cost, a));
    }
    kk[b].clear();
    return;
}

int get2(int v) {
    return (p[v] == v ? v : p[v] = get2(p[v]));
}

void merge2(int a, int b) {
    a = get2(a);
    b = get2(b);
    if (a == b) {
        return;
    }
    if (rk[a] < rk[b]) {
        swap(a, b);
    }
    p[b] = a;
    rk[a] += rk[b];
    return;
}

struct ed {
    int f, sec, cost, num;
};

bool cmp(ed a, ed b) {
    return a.cost < b.cost;
}

vector<ed> arr, arr2;

_ void source() {
    int n, m;
    cin >> n >> m;
    arr.rsz(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].f >> arr[i].sec >> arr[i].cost;
        arr[i].num = i;
    }
    arr2 = arr;
    sort(all(arr2), cmp);
    for (int i = 1; i <= n; i++) {
        make1(i);
    }
    vector<bool> bad(m, 0);
    for (int i = 0; i < m; i++) {
        merge1(arr2[i].f, arr2[i].sec, arr2[i].cost);
        if (i + 1 < m && arr2[i].cost != arr2[i + 1].cost) {
            int l = i + 1, r = i + 1;
            while (r < m && arr2[l].cost == arr2[r].cost) {
                if (get1(arr2[r].f) == get1(arr2[r].sec)) {
                    bad[arr2[r].num] = true;
                }
                r++;
            }
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        vector<ed> cur;
        int cnt;
        bool t = true;
        cin >> cnt;
        cur.rsz(cnt);
        for (int j = 0; j < cnt; j++) {
            int num;
            cin >> num;
            num--;
            if (bad[num]) {
                t = false;
            }
            cur[j] = arr[num];
        }
        sort(all(cur), cmp);
        //cout << "COMPLETE1" << endl;
        for (int j = 0; j < cnt; j++) {
            if (!j || cur[j].cost != cur[j - 1].cost) {
                int l = j, r = j;
                while (r < cnt && cur[r].cost == cur[l].cost) {
                    int a = cur[r].f;
                    auto it = lower_bound(all(change_color[a]), mk(cur[j].cost, 1));
                    assert(it != change_color[a].begin());
                    it--;
                    int now = it->sec;
                    p[now] = now;
                    p[a] = now;
                    auto it2 = lower_bound(all(change_rk[now]), mk(cur[j].cost, 1));
                    assert(it2 != change_rk[now].begin());
                    it2--;
                    rk[now] = it2->sec;

                    a = cur[r].sec;
                    it = lower_bound(all(change_color[a]), mk(cur[j].cost, 1));
                    assert(it != change_color[a].begin());
                    it--;
                    now = it->sec;
                    p[now] = now;
                    p[a] = now;
                    it2 = lower_bound(all(change_rk[now]), mk(cur[j].cost, 1));
                    assert(it2 != change_rk[now].begin());
                    it2--;
                    rk[now] = it2->sec;
                    r++;
                }
            }
            if (get2(cur[j].f) == get2(cur[j].sec)) {
                t = false;
            }
            merge2(cur[j].f, cur[j].sec);
        }
        cout << (t ? "YES" : "NO") << endl;
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