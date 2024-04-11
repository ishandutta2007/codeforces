#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXN = 6e5 + 1;

int dsu[MAXN];
int s[MAXN];

int get(int i) {
    while (dsu[i] != i) {
        i = dsu[i];
    }
    return i;
}

vector<pair<pair<int, int>, int>> event;

void add(int i, int j) {
    i = get(i), j = get(j);
    if (s[i] < s[j]) swap(i, j);
    event.pb({{i, j}, s[i]});
    s[i] += s[j];
    dsu[j] = i;
}


int n, m, q;
int a[MAXN], b[MAXN], w[MAXN];
int num[MAXN];
bool OK[MAXN];
vector<pair<int, int>> ask[MAXN];
vector<int> id;
vector<int> p[MAXN];

bool cmp(int i, int j) {
    return w[i] < w[j];
}

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        dsu[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> w[i];
        id.pb(i);
    }
    sort(id.begin(), id.end(), cmp);
    int L = 0;
    while (L < m) {
        int R = L;
        while (R < m && w[id[L]] == w[id[R]]) {
            ++R;
        } 
        for (int i = L; i < R; ++i) {
            num[id[i]] = L;
        }
        L = R;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        OK[i] = true;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            --v;
            p[i].pb(v);
            ask[num[v]].pb({i, v});
        }       
    }
    L = 0;
    while (L < m) {
        int R = L;
        while (R < m && w[id[L]] == w[id[R]]) {
            ++R;
        }
        int Ln = 0;
        while (Ln < ask[L].size()) {
            int Rn = Ln;
            while (Rn < ask[L].size() && ask[L][Ln].x == ask[L][Rn].x) {
                ++Rn;
            }
            int lst = event.size();
            for (int i = Ln; i < Rn; ++i) {
                int v1 = get(a[ask[L][i].y]);
                int v2 = get(b[ask[L][i].y]);
                if (v1 == v2) {
                    OK[ask[L][i].x] = false;
                    break;
                } else {
                    add(v1, v2);
                }
            }
            while (event.size() != lst) {
                auto v = event.back();
                event.pop_back();
                s[v.x.x] = v.y;
                dsu[v.x.y] = v.x.y;
            }
            Ln = Rn;
        }
        for (int i = L; i < R; ++i) {
            if (get(a[id[i]]) != get(b[id[i]])) {
                add(a[id[i]], b[id[i]]);
            } 
        }
        L = R;
    }
    for (int i = 0; i < q; ++i) {
        if (OK[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}