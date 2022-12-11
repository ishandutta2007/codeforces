#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 7;
int par[MAX_N];
int sz[MAX_N];
bool beg[MAX_N];
map <int, int> sz_to_num;

int find_par(int v) {
    if (par[v] == v) return v;
    par[v] = find_par(par[v]);
    return par[v];
}

void extr(int n) {
    sz_to_num[n]--;
    if (sz_to_num[n] == 0) {
        sz_to_num.erase(n);
    }
}

void merge_dsu(int v, int u) {
    v = find_par(v);
    u = find_par(u);
    if (u == v) return;
    extr(sz[v]);
    extr(sz[u]);
    if (sz[v] > sz[u]) {
        sz[v] += sz[u];
        par[u] = v;
        sz_to_num[sz[v]]++;
    } else {
        sz[u] += sz[v];
        par[v] = u;
        sz_to_num[sz[u]]++;
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    set <int> now;
    map <int, vector <int> > poses;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        now.insert(a[i]);
        poses[a[i]].push_back(i);
        par[i] = i;
        sz[i] = 1;
        beg[i] = 0;
    }
    int best = 0, ans = *now.begin() + 1, v;
    while (!now.empty()) {
        v = (*now.begin());
        now.erase(v);
        for (int elem : poses[v]) {
            beg[elem] = 1;
            sz_to_num[1]++;
            if (elem > 0 && beg[elem - 1]) merge_dsu(elem - 1, elem);
            if (elem < n - 1 && beg[elem + 1]) merge_dsu(elem, elem + 1);
        }
        if (sz_to_num.size() == 1 && (*sz_to_num.begin()).second > best) {
            best = (*sz_to_num.begin()).second;
            ans = v + 1;
        }
    }
    cout << ans << endl;
    return 0;
}