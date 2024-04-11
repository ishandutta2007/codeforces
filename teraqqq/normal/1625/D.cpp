#include <bits/stdc++.h>

#include <cassert>

using namespace std;

const int N = 3e5+7;
const int W = 30;
const int SZ = N * W;

int go[2][SZ], id[SZ], vc;
vector<int> a;

int new_vertex() {
    go[0][vc] = -1;
    go[1][vc] = -1;
    id[vc] = -1;
    assert(vc < SZ);
    return vc++;
}

void add_num(int v, int x, int w, int jid) {
    for (int i = w; i--; ) {
        int bit = (x >> i) & 1;
        if (go[bit][v] == -1) go[bit][v] = new_vertex();
        v = go[bit][v];
        id[v] = jid;
    }
}

bool find_pair(const int v, const int u, const int k, int w, vector<int>& out) {
    if (v < 0 || u < 0) return false;

    // cout << "ft " << v << " " << u << " " << k << " " << w << endl;

    if (w == 0) {
        out.push_back(id[v]);
        out.push_back(id[u]);
        // cout << id[v] << " " << id[u] << endl;
        assert((a[id[v]-1] ^ a[id[u]-1]) >= k);
        return true;
    } else {
        w--;
        if ((k >> w) & 1) {
            if (find_pair(go[0][v], go[1][u], k, w, out)) return true;
            if (v != u && find_pair(go[1][v], go[0][u], k, w, out)) return true;
        } else {
            if (go[0][v] > 0 && go[1][u] > 0) {
                out.push_back(id[go[0][v]]);
                out.push_back(id[go[1][u]]);
                return true;
            }

            if (go[1][v] > 0 && go[0][u] > 0) {
                out.push_back(id[go[1][v]]);
                out.push_back(id[go[0][u]]);
                return true;
            }

            if (find_pair(go[0][v], go[0][u], k, w, out)) return true;
            if (find_pair(go[1][v], go[1][u], k, w, out)) return true;
        }
    }

    return false;
}

void solve(int v, int w, int k, vector<int>& out) {
    // cout << v << " " << w << " " << k << " solve" << endl;
    if (v < 0) return;
    if (w == 0) {
        out.push_back(id[v]);
        return;
    }

    w--;
    if ((k >> w) & 1) {
        int sav = size(out);
        if (!find_pair(v, v, k, w+1, out)) out.push_back(id[v]);
    } else {
        solve(go[0][v], w, k, out);
        solve(go[1][v], w, k, out);
    }
}

vector<int> solve_fast(const int n, const int k,  const vector<int>& a) {
    vector<int> res;

    if (!k) {
        res.resize(n);
        iota(res.begin(), res.end(), 1);
        return res;
    }

    vc = 0;
    int rt = new_vertex();
    for (int i = n; i--; ) add_num(rt, a[i], W, i+1);
    solve(rt, W, k, res);
    if (size(res) < 2) res.clear();
    return res;
}

vector<int> solve_stupid(const int n, const int k, const vector<int>& a) {
    assert(n <= 20);

    vector<int> res;

    for (int mask = 1 << n; mask--; ) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if ((~mask >> i) & 1) continue;
            for (int j = 0; j < i; ++j) {
                if ((~mask >> j) & 1) continue;
                if ((a[i] ^ a[j]) < k) { ok = false; break; }
            }
            if (!ok) break;
        }

        if (ok) {
            vector<int> cur;
            for (int i = 0; i < n; ++i)  {
                if ((mask >> i) & 1) cur.push_back(i + 1);
            }

            if (size(cur) > size(res)) res = cur;
        }
    }

    if (size(res) < 2) res.clear();
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

/*
    int n; cin >> n;
    a.resize(n);

    auto time_begin = chrono::high_resolution_clock::now();

    mt19937 rng(1337228);
    uniform_int_distribution<int> val_distr(0, (1 << W) - 1);

    bool found = false;

    while (true) {
        auto time_cur = chrono::high_resolution_clock::now();
        if ((time_cur - time_begin) > std::chrono::seconds(4)) break;

        // cout << "RUN!" << endl;

        for (int& x : a) x = val_distr(rng);
        int k = val_distr(rng);

        auto pans = solve_fast(n, k, a);
        auto jans = solve_stupid(n, k, a);

        if (size(pans) != size(jans)) {
            cout << "You're awful!!!" << endl;
            cout << n << " " << k << endl;
            for (int x : a) cout << x << ' ';
            cout << endl;

            cout << "pans:"; for (int x : pans) cout << " " << x; cout << "\n";
            cout << "jans:"; for (int x : jans) cout << " " << x; cout << "\n";

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Task failed successful" << endl;
    }
//*/

//*
    int n, k; cin >> n >> k;
    a.resize(n);
    for (int& x : a) cin >> x;

    auto res = solve_fast(n, k, a);

    if (size(res) < 2) {
        cout << -1 << '\n';
    } else {
        cout << size(res) << '\n';
        for (int x : res) cout << x << ' ';
        cout << '\n';
    }
//*/
}